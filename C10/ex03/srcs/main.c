/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 16:54:07 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	err_all_failed(char *str)
{
	ft_putstrerr(str);
	ft_putstrerr(": all input file arguments failed\n");
	return (1);
}

void	process_buffer(t_file_info *info, int *is_repeated)
{
	if (info->nb_read == 16 && info->offset > 0
		&& ft_strncmp(info->buffer, info->prev_buffer, 16) == 0)
	{
		if (!*is_repeated)
			write(1, "*\n", 2);
		*is_repeated = 1;
	}
	else
	{
		print_row(info->buffer, info->offset, 16);
		*is_repeated = 0;
	}
	str_copy(info->prev_buffer, info->buffer, 16);
	info->offset += info->partial_size;
	info->partial_size = 0;
}

int	ft_display_file(char *str, t_file_info *info, char *prog_name)
{
	int		is_repeated;

	is_repeated = 0;
	info->fd = open(str, O_RDONLY);
	if (info->fd == -1)
		return (print_error(str, prog_name), 1);
	str_copy(info->prev_buffer, info->buffer, 16);
	info->nb_read = -1;
	while (info->nb_read != 0)
	{
		info->nb_read = read(info->fd, info->buffer + info->partial_size,
				16 - info->partial_size);
		if (info->nb_read == -1)
			return (print_error(str, prog_name), close(info->fd), 1);
		info->partial_size += info->nb_read;
		if (info->partial_size == 16)
			process_buffer(info, &is_repeated);
	}
	return (close (info->fd), 1);
}

void	free_files(char ***files, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free((*files)[i]);
		i++;
	}
	free(*files);
}

int	main(int argc, char **argv)
{
	int			i;
	t_file_info	info;
	char		**files;

	files = check_flag_c(argv, &argc);
	if (!files[0])
		return (free_files(&files, argc), 1);
	i = 0;
	info.offset = 0;
	info.partial_size = 0;
	while (i < argc)
	{
		if (!ft_display_file(files[i], &info, argv[0]))
			return (1);
		i++;
	}
	if (info.partial_size > 0)
		print_row(info.buffer, info.offset, info.partial_size);
	info.offset += info.partial_size;
	if (info.offset == 0)
		return (err_all_failed(argv[0]));
	write_address(info.offset, 1);
	return (free_files(&files, argc), 0);
}
