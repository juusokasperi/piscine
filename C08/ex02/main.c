/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:26:29 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 23:40:03 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	value;

	if (argc != 2)
	{
		printf("Error: Usage %s <value>\n", argv[0]);
		return (1);
	}
	value = atoi(argv[1]);
	printf("Absolute value of %i is %i\n", value, ABS(value));
	return (0);
}
