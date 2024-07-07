/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:21:44 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/05 21:18:23 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(int argc, char **argv)
{
	int	*range;
	int	length;

	if (argc != 3)
	{
		printf("Error. Usage \"%s <min> <max>\"\n", argv[0]);
		return (1);
	}
	length = ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2]));
	if (length)
	{
		printf("length is %d\n", length);
		printf("first element in string is %d\n", range[0]);
		printf("last element in string is %d\n", range[length - 1]);
	}
	else
	{
		printf("Value of length is: %i\n", length);
		printf("0 = null pointer, -1 = error\n");
	}
	free(range);
	return (0);
}
