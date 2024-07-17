/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 11:16:43 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	process_buffer(t_file_info *info, int *repeat, int *line_size)
{
	if (info->nb_read == 16 && info->offset > 0
		&& ft_strncmp(info->buffer, info->prev_buffer, 16) == 0)
	{
		if (!*repeat)
			write(1, "*\n", 2);
		*repeat = 1;
	}
	else
	{
		print_row(info->buffer, info->offset, 16);
		*repeat = 0;
	}
	str_copy(info->prev_buffer, info->buffer, 16);
	*line_size = 0;
	info->offset += 16;
}

int	ft_display_file(char *str, t_file_info *info, int *partial_size)
{
	int		repeat;
	int		line_size;

	line_size = *partial_size;
	repeat = 0;
	info->file_descriptor = open(str, O_RDONLY);
	if (info->file_descriptor == -1)
		return (print_error(str), 1);
	str_copy(info->prev_buffer, info->buffer, 16);
	while (1)
	{
		info->nb_read = read(info->file_descriptor,
				info->buffer + line_size, 16 - line_size);
		if (info->nb_read <= 0)
			break ;
		line_size += info->nb_read;
		if (line_size == 16)
			process_buffer(info, &repeat, &line_size);
	}
	if (info->nb_read == -1)
		return (print_error(str), close(info->file_descriptor), 1);
	*partial_size = line_size;
	return (close (info->file_descriptor), 1);
}

int	main(int argc, char **argv)
{
	int			i;
	int			partial_size;
	t_file_info	info;

	i = 1;
	info.offset = 0;
	partial_size = 0;
	fill_zeros(info.prev_buffer);
	while (i < argc)
	{
		if (!ft_display_file(argv[i], &info, &partial_size))
			return (1);
		i++;
	}
	if (partial_size > 0)
	{
		print_row(info.buffer, info.offset, partial_size);
		info.offset += partial_size;
	}
	write_address(info.offset);
	write(1, "\n", 1);
	return (0);
}
