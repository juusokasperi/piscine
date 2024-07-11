/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:04:51 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 20:20:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

void	print_char(char c)
{
	write(1, &c, 1);	
}

void	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 17;
	b = 5;
	ft_div_mod(a, b, &div, &mod);
	print_char(div + '0');
	print_char(mod + '0');
}
