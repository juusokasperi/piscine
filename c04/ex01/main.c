/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:49:15 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 20:52:38 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("ERROR: Invalid parameters.");
		return (1);
	}
	ft_putstr(argv[1]);
	return (0);
}
