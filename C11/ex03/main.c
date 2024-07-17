/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 20:05:33 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int(*f)(char*));

int	has_capital_b(char *str)
{
	while (*str)
	{
		if (*str == 'b')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	main(void)
{
	char **tab;

	tab = (char **)malloc(3 * sizeof(char));
	tab[0] = (char *)malloc(5 * sizeof(char));
	tab[1] = (char *)malloc(5 * sizeof(char));
	tab[2] = (char *)malloc(1 * sizeof(char));
	tab[0] = "tebti";
	tab[1] = "besbi";
	tab[2] = 0;
	int		i;

	i = ft_count_if(tab, 3, &has_capital_b);
	printf("i is %i\n", i);
}
