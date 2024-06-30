/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:47:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/06/30 15:52:54 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line(int x, char c1, char c2)
{
	int	w;

	ft_putchar(c1);
	w = 1;
	while (w < x)
	{
		if (w < x - 1)
			ft_putchar(c2);
		if (w == x - 1)
			ft_putchar(c1);
		w++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	h;

	h = 0;
	if (x < 1 || y < 1)
	{
		return ;
	}
	while (h < y)
	{
		if (h == 0)
			line(x, 'o', '-');
		if (h > 0 && h < y - 1)
			line(x, '|', ' ');
		if (y > 1 && h == y - 1)
			line(x, 'o', '-');
		h++;
	}	
}
