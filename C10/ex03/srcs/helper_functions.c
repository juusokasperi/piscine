/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:07:23 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 17:39:15 by jrinta-          ###   ########.fr       */
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

void	str_copy(char *dest, char *src, int nb_read)
{
	while (nb_read--)
		*dest++ = *src++;
}
