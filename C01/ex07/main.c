/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:25:48 by jrinta-           #+#    #+#             */
/*   Updated: 2024/08/05 14:30:18 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[]= {0, 1, 2, 3, 4};
	int	i;

	i = 0;
	printf("Before reversing tab is:\n");
	while (i < 4)
	{
		printf("Tab[%i] is %i, ", i, tab[i]);
		i++;
	}
	printf("Tab[%i] is %i.\n", i, tab[i]);
	ft_rev_int_tab(tab, 5);
	i = 0;
	printf("After reversing tab is:\n");
	while (i < 4)
	{
		printf("Tab[%i] is %i, ", i, tab[i]);
		i++;
	}
	printf("Tab[%i] is %i.\n", i, tab[i]);
	return (0);
}
