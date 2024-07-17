/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 11:15:10 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	write_address(int offset)
{
	char	address[8];
	char	*hex;
	int		i;
	int		digit;

	hex = "0123456789abcdef";
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

void	write_hex(char *buffer, int nb_read)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
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
