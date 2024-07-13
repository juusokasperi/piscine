/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:21:32 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/13 11:08:49 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	unsigned long	str_len;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	str_len = (unsigned long)max - (unsigned long)min;
	*range = malloc(str_len * 4);
	if (*range == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min++;
		i++;
	}
	return (i);
}
