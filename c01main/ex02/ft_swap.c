/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:44:56 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 19:59:00 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void	main(void)
{
	int a;
	int b;
	char a_char;
	char b_char;
	char c; 

	a = 1;
	b = 2;
	c = ' ';
	a_char = a + '0';
	b_char = b + '0';

	write(1, &a_char, 1);
	write(1, &b_char, 1);
	write(1, &c, 1);
	ft_swap(&a, &b);
        a_char = a + '0';
        b_char = b + '0';

        write(1, &a_char, 1);
        write(1, &b_char, 1);
}
