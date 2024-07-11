/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:54 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:39:31 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	if (c < 16)
	{
		write(1, "0", 1);
		write(1, &hex[c], 1);
	}
	if (c >= 16)
	{
		write(1, "1", 1);
		write(1, &hex[c - 16], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str > 31)
			write(1, str, 1);
		else
			print_hex(*str);
		str++;
	}
}
