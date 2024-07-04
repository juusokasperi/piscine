/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:05:29 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 08:46:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.\n");
		return (1);
	}

	nbr = ft_sqrt(atoi(argv[1]));
	printf("Square root of %s is: %i\n", argv[1], nbr);
	return (0);
}
