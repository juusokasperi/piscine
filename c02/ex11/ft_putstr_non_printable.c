/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:54 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 18:41:22 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_hex(char c)
{	
	print_char('\\');
	if (c < 16)
		print_char('0');
	if (c > 16)
		print_char('1');
	if (c <= 9 || (c >= 16 && c <= 25))
	{
		if (c <= 9)
			print_char(c + '0');
		if (c >= 16)
			print_char(c - 16);
	}
	if ((c >= 10 && c <= 15) || c >= 26)
	{
		if (c <= 15)
			print_char(c + 87);
		if (c >= 26)
			print_char(c + 71);
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
