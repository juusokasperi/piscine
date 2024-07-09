/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 05:56:47 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 18:30:15 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*str;
	long	i;
	long	range;

	if (min >= max)
		return (0);
	range = (long)max - (long)min;
	if (range < 0)
		range = -range;
	str = malloc(range * 4);
	i = 0;
	while (i < range)
	{
		str[i] = min++;
		i++;
	}
	return (str);
}
