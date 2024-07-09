/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:45:31 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/10 00:56:50 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <unistd.h>

void	ft_putnbr(int nb);

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	ft_putnbr(point.x);
	write(1, "\n", 1);
	ft_putnbr(point.y);
	write(1, "\n", 1);
	return (0);
}
