/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:59:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 13:11:32 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void print_char(

void ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;

	while (a <= 99)
	{
		b = a + 1
		while (b <= 99)
		{
			print_char(a);
			print_char(' ');
			print_char(b);
			print_char(',');
			print_char(' ');
			b = b + 1;
		}
		a = a + 1
	}
}
