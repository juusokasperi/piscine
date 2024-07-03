/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:41:20 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 20:11:38 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0 || (power == 0 && nb == 0))
		return (0);
	if (power > 1)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
