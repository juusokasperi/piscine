/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:14:39 by jrinta-           #+#    #+#             */
/*   Updated: 2024/08/05 14:17:13 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	div;
	int	mod;
	int	a;
	int	b;

	a = 17;
	b = 5;
	ft_div_mod(a, b, &div, &mod);
	printf("%i / %i = %i\n", a, b, div);
	printf("%i %% %i = %i\n", a, b, mod);
	return (0);
}
