/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:38:43 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 13:55:59 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.\n");
		return (1);
	}
	nbr = ft_is_prime(atoi(argv[1]));
	if (nbr)
		printf("Number %s IS a prime number.\n", argv[1]);
	else
		printf("Number %s IS NOT a prime number.\n", argv[1]);
	return (0);
}
