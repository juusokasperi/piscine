/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:01:24 by jrinta-           #+#    #+#             */
/*   Updated: 2024/08/05 14:12:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	nbr;

	nbr = 10;
	printf("BEFORE\nNbr is: %i\n----------\n", nbr);
	ft_ft(&nbr);
	printf("AFTER\nNbr is: %i\n----------\n", nbr);
	return (0);
}
