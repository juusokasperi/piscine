/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:41:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 20:05:49 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 3)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	nbr = ft_iterative_power(atoi(argv[1]), atoi(argv[2]));
	printf("Value of power %s applied to %s is %i\n", argv[2], argv[1], nbr);
	return (0);
}
