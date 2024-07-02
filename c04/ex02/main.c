/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:54:15 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 22:04:43 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_putnbr(int nb);

int		main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	i = atoi(argv[1]);
	ft_putnbr(i);
}
