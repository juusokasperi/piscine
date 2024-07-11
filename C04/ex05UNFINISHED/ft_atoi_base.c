/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:03:57 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 18:31:10 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	isspace(int arg)
{
	if (arg == ' ' || (arg >= 9 && arg <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int s;
	int atoi;

	s = 1;
	i = 0;
	atoi = 0;
	while (isspace(str[i]) && str[i] != '\0')
	{
		i++;
	}
	while(str[i] != '\0')
	{
		if ((s == -1 && str[i] == '-')
			|| (s == 1 && str[i] == '-'))
		{
			s *= -1;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			atoi = (atoi * 10) + str[i] - '0';
		}
		if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
		{
			break;
		}
		i++;
	}
	return(s * atoi);
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
		if (base[i] < 32 || base[i] == '+' || base[i] == '-'
			|| base[i] == '!')
			return (0);
		i++;
	}
	return (1);
}

void	print_nbr_base(int nbr, int base_size, char *base)
{
	if (nbr >= base_size)
	{
		print_nbr_base(nbr / base_size, base_size, base);
		print_nbr_base(nbr % base_size, base_size, base);
	}
	if (nbr < base_size)
		write(1, &base[nbr], 1);
}

void	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	base_size;

	nbr = ft_atoi(str);
	base_size = 0;
	if (!check_base(base))
		return ;
	while (base[base_size] != '\0')
		base_size++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	print_nbr_base(nbr, base_size, base);
}
