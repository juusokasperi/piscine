/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 15:33:08 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
# include <errno.h>
# include <string.h>


void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

void	print_error(char *str)
{
	ft_putstr("hexdump: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
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
	write(1, "\n", 1);
}
void	print_hex(char *buffer, int offset)
{
	int	i;

	write_address(offset);
	i = 0;
	(void)buffer;
}
# include <stdio.h>
int	ft_display_file(char *str)
{
	char	buffer[16];
	int		file_descriptor;
	int		nb_read;
	int		offset;

	offset = 0;
	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
	{
		print_error(str);
		return (0);
	}
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 16);
		if (nb_read == -1)
		{
			print_error(str);
			return (0);
		}
		print_hex(buffer, offset);
		offset += nb_read;
		printf("read is %i and offset is %i\n", nb_read, offset);
	}
	close(file_descriptor);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_display_file(argv[i]);
		i++;
	}
	return (0);
}
