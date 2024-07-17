/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 06:23:12 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstrerr(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

void	print_error(char *str)
{
	ft_putstrerr("hexdump: ");
	ft_putstrerr(str);
	ft_putstrerr(": ");
	ft_putstrerr(strerror(errno));
	ft_putstrerr("\n");
}
void	write_address(int offset)
{
	char	address[8];
	char	hex[16] = "0123456789abcdef";
	int		i;
	int		digit;

	i = 7;
	while (i >= 0)
	{
		digit = offset % 16;
		address[i] = hex[digit];
		offset = offset / 16;
		i--;
	}
	write(1, address, 8);
	write(1, "  ", 2);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (i < n - 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	write_hex(char *buffer, int nb_read)
{
	char	hex[16] = "0123456789abcdef";
	int		i;

	i = 0;
	while (i < nb_read)
	{
		write (1, &hex[buffer[i] / 16], 1);
		write (1, &hex[buffer[i] % 16], 1);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		if (i == 7)
			write(1, " ", 1);
		write(1, "   ", 3);
		i++;
	}
	write(1, " ", 1);
}

void	write_printables(char *buffer, int nb_read)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (i < nb_read)
	{
		if (buffer[i] < 32 || buffer[i] > 126)
			write(1, ".", 1);
		else
			write(1, &buffer[i], 1);
		i++;
	}
	write(1, "|", 1);
}
void	print_row(char *buffer, int offset, int nb_read)
{
	write_address(offset);
	if (nb_read != 0)
	{
		write_hex(buffer, nb_read);
		write_printables(buffer, nb_read);
	}
	write(1, "\n", 1);
}

void str_copy(char *dest, char *src, int nb_read)
{
    while (nb_read--)
        *dest++ = *src++;
}

void	process_buffer(t_file_info *info, int *repeat, int *line_size)
{
	if (info->nb_read == 16 && info->offset > 0 &&
		ft_strncmp(info->buffer, info->prev_buffer, 16) == 0)
	{
		if (!*repeat)
			write(1, "*\n", 2);
			*repeat = 1;
	}
	else
	{
		print_row(info->buffer, info->offset, info->nb_read);
		*repeat = 0;
	}
	str_copy(info->prev_buffer, info->buffer, 16);
	*line_size = 0;
	info->offset += 16;
}

int	ft_display_file(char *str, int *offset, char *partial_line, int *partial_size)
{
	t_file_info	info;
	int		repeat;
	int		line_size;

	line_size = *partial_size;
	info.offset = *offset;
	str_copy(info.buffer, partial_line, line_size);
	str_copy(info.prev_buffer, info.buffer, 16);
	repeat = 0;
	info.file_descriptor = open(str, O_RDONLY);
	if (info.file_descriptor == -1)
		return(print_error(str), 0);
	info.nb_read = -1;
	while (info.nb_read != 0)
	{
		info.nb_read = read(info.file_descriptor, info.buffer + line_size, 16 - line_size);
		line_size += info.nb_read;
		if (line_size == 16)
			process_buffer(&info, &repeat, &line_size);
	}
	if (info.nb_read == -1)
		return(print_error(str), close(info.file_descriptor), 0);
	*partial_size = line_size;
	str_copy(partial_line, info.buffer, line_size);
	*offset = info.offset;
	return(close (info.file_descriptor), 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	offset;
	int partial_size;
	char partial_line [16];

	i = 1;
	offset = 0;
	partial_size = 0;
	while (i < argc)
	{
		if (!ft_display_file(argv[i], &offset, partial_line, &partial_size))
			return (1);
		i++;
	}
	if (partial_size > 0)
	{
		print_row(partial_line, offset, partial_size);
		offset += partial_size;
	}
	write_address(offset);
	write(1, "\n", 1);
	return (0);
}
