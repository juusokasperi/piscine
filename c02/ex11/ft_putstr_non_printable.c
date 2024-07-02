/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:54 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 14:50:11 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	print_char('\\');
	if (c < 16)
	{
		print_char('0');
		print_char(hex[c]);
	}
	if (c >= 16)
	{
		print_char('1');
		print_char(hex[c - 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31)
			print_char(str[i]);
		else
			print_hex(str[i]);
		i++;
	}
}
