/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:58:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 06:07:01 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	i = ft_atoi(argv[1]);
	printf("Value of i is: %i \n", i);
	return (0);
}
