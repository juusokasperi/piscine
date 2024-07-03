/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:05:53 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 20:04:46 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	if (nb < -1)
		nb = nb * ft_recursive_factorial(nb + 1);
	return (nb);
}
