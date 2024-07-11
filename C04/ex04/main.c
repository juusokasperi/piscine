/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:03:54 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 12:45:21 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc != 3)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	printf("Integer is: %s\nBase is: %s\n", argv[1], argv[2]);
	nbr = atoi(argv[1]);
	ft_putnbr_base(nbr, argv[2]);
}
