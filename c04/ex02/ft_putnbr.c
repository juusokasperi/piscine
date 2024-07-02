/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:54:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 22:47:11 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	i = nb;

	420
	while (i >= 10)
	{
		i /= 10;
		if (i < 10)
		{
			print_char(i + '0');
			i = nb / 10;
		}
	}
	if (nb < 10)
		print_char(nb + '0');
}
