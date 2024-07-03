/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:05:53 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 20:27:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sign;
	int	i;
	int	temp;

	temp = 1;
	sign = 1;
	i = 1;
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
	}
	while (i < nb)
	{
		temp = temp * (i + 1);
		i++;
	}
	return (sign * temp);
}
