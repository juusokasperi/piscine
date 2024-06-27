/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:23:20 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 20:29:43 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;

	c = *a / *b;
	d = *a % *b;
	*a = c;
	*a = d;
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	main(void)
{
	int a;
	int b;
	
	a = 17;
	b = 5;

	ft_ultimate_div_mod(&a, &b);
	print_char(a + '0');
	print_char(b + '0');
}
