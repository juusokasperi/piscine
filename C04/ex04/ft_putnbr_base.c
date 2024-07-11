/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:03:57 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 12:43:59 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*base_contents(int base_size, char *base)
{
	if (base_size == 8 && base[0] == 'p' && base[1] == 'o'
		&& base[2] == 'n' && base[3] == 'e' && base[4] == 'y'
		&& base[5] == 'v' && base[6] == 'i' && base[7] == 'f')
		return ("01234567");
	return (base);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				return (0);
		}
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-'
			|| base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

void	print_nbr_base(int nbr, int base_size, char *base_container)
{
	if (nbr >= base_size)
		print_nbr_base(nbr / base_size, base_size, base_container);
	write(1, &base_container[nbr % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	char	*base_container;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	if (!check_base(base))
		return ;
	base_container = base_contents(base_size, base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		print_nbr_base(-(nbr / base_size), base_size, base_container);
		write(1, &base_container[-(nbr % base_size)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	print_nbr_base(nbr, base_size, base_container);
}
