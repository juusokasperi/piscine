/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:07:06 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 16:21:35 by jrinta-          ###   ########.fr       */
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
	printf("String Antti compared to string Artti is %i", ft_strcmp("Antti", "Artti"));
	printf(" because n's decimal is 110 and r is 116, so 110 - 116 is %i\n", 110 - 116);
	return (0);
}
