/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bkp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 05:33:55 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
# include <errno.h>
# include <string.h>
#include <stdio.h>


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
    char *d = dest;
    char *s = src;
    while (nb_read--)
        *d++ = *s++;
}

int	ft_display_file(char *str)
{
	char	buffer[16];
	char	prev_buffer[16];
	int		file_descriptor;
	int		nb_read;
	int		offset;
	int		repeat;
	int		line_size = 0;

	repeat = 0;
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
			close(file_descriptor);
			return (0);
		}
		if (nb_read == 16 && offset > 0
			&& ft_strncmp(buffer, prev_buffer, 16) == 0)
		{
			if (!repeat)
			{
				write(1, "*\n", 2);
				repeat = 1;
			}
		}
		else
			print_row(buffer, offset, nb_read);
		str_copy(prev_buffer, buffer, nb_read);
		offset += nb_read;
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
