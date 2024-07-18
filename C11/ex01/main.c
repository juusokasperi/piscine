/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:49:17 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 11:28:29 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		print_char('-');
		print_char('2');
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	if (nb < 10)
	{
		print_char(nb + '0');
	}
}

int	ft_increment(int nb)
{
	return (nb + 1);
}

int	*ft_map(int *tab, int length, int (*f)(int));

int	main(void)
{
	int	*array;
	int	nbr_array[6] = {0, 1, 2, 3, 4, 5};
	int	i;

	i = 0;
	array = ft_map(nbr_array, 6, &ft_increment);
	while (i < 6)
	{
		ft_putnbr(array[i]);
		i++;
	}
	free(array);
}
