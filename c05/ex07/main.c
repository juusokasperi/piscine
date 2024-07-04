/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:57:09 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 15:19:38 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.\n");
		return (1);
	}
	nbr = ft_find_next_prime(atoi(argv[1]));
	if (nbr == atoi(argv[1]))
		printf("Number %i IS a prime number.", nbr);
	else
	{
		printf("First prime number after %s is %i\n", argv[1], nbr);
	}
	return (0);
}
