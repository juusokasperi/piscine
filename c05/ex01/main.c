/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:03:15 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 19:27:46 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_factorial(int nb);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	nbr = ft_recursive_factorial(atoi(argv[1]));
	printf("Factorial of %s is %i\n", argv[1], nbr);
	return (0);
}
