/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:59:28 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 15:20:46 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb - 1;
	if (nb <= 2)
		return (2);
	while (i > 1)
	{
		if (nb % i == 0)
		{
			nb = ft_find_next_prime(nb + 1);
			return (nb);
		}
		i--;
	}
	return (nb);
}
