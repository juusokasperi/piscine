/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:07:06 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 23:04:55 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("a is %i and b is %i\n", a, b);
	ft_putchar('c');
	ft_putchar('\n');
	ft_swap(&a, &b);
	printf("a is %i and b is %i\n", a, b);
	ft_putstr("Testi String");
	ft_putchar('\n');
	a = ft_strlen("Testi String");
	printf("Testi String is %i characters long\n", a);
	printf("Antti compared to Artti is %i\n", ft_strcmp("Antti", "Artti"));
	return (0);
}
