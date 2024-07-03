/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:12:37 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 20:16:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.\n");
		return (1);
	}
	nbr = ft_fibonacci(atoi(argv[1]));
	printf("Element #%s of the Fibonacci sequence is: %i\n", argv[1], nbr);
	return (0);
}
