/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:03:54 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/03 18:26:13 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_atoi_base(char *str, char *base);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 3)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	printf("First argument is: \"%s\"\nSecond argument is: \"%s\"\n", argv[1], argv[2]);
	printf("Result of ft_atoi_base below:\n");
	ft_atoi_base(argv[1], argv[2]);
}
