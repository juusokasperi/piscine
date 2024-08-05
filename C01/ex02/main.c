/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:21 by jrinta-           #+#    #+#             */
/*   Updated: 2024/08/05 14:14:19 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 13;

	printf("BEFORE\na is: %i\nb is: %i\n----------\n", a, b);
	ft_swap(&a, &b);
	printf("AFTER\na is: %i\nb is: %i\n----------\n", a, b);
	return (0);
}
