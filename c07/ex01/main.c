/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 05:57:07 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 18:47:59 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(int argc, char **argv)
{
	int				*string;
	unsigned long	range;
	int				min;
	int				max;

	if (argc != 3)
	{
		printf("Error. Usage \"%s <min> <max>\"\n", argv[0]);
		return (1);
	}
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	string = ft_range(min, max);
	range = (long)max - (long)min;
	if (string)
	{
		printf("range is %lu\n", range);
		printf("first element in string is %d\n", string[0]);
		printf("last element in string is %d\n", string[range - 1]);
	}
	else
		printf("String is (null) \n");
	free(string);
	return (0);
}
