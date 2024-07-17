/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:38:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 13:38:10 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_error(char *str)
{
	ft_putstr("tail: cannot open '", 2);
	ft_putstr(str, 2);
	ft_putstr("' for reading: ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

void	print_error_dir(char *str)
{
	print_name(str);
	ft_putstr("tail: error reading '", 2);
	ft_putstr(str, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

void	print_name(char *str)
{
	ft_putstr("==> ", 1);
	ft_putstr(str, 1);
	ft_putstr(" <==", 1);
	ft_putstr("\n", 1);
}

void	print_ten(char *file, int file_size)
{
	int	new_lines;
	int	start_read;

	new_lines = -1;
	start_read = file_size;
	while (start_read > 0)
	{
		if (file[start_read - 1] == '\n')
			new_lines++;
		if (new_lines == 10)
			break ;
		start_read--;
	}
	write(1, file + start_read, file_size - start_read);
}

void	print_n_bytes(char *file, int bytes_to_read, int file_size)
{
	int	start_read;

	start_read = file_size - bytes_to_read;
	if (bytes_to_read > file_size)
		write(1, file, file_size);
	else
		write(1, file + start_read, bytes_to_read);
}
