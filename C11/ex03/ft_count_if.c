/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:41:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 20:05:44 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
