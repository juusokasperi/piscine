/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:56:55 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/13 16:00:35 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

void				ft_show_tab(struct s_stock_str *par);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int argc, char **argv)
{
	t_stock_str	*strs;
	int			i;

	if (argc < 2)
	{
		printf("Error: No strings found.\n");
		return (1);
	}
	strs = ft_strs_to_tab(argc - 1, argv + 1);
	i = 0;
	ft_show_tab(strs);
	while (strs[i].str)
	{
		free(strs[i].copy);
		i++;
	}
	free(strs);
	return (0);
}
