/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:34:45 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/28 20:47:39 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	spare;
	int	*start;
	int	*end;

	start = tab;
	end = tab + (size - 1);
	while (start < end)
	{
		spare = *start;
		*start = *end;
		*end = spare;
		start++;
		end--;
	}
}
