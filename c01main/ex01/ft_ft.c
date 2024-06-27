/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:38:45 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 19:40:15 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *********nbr)
{
	*********nbr = 42;
}

void	main(void)
{
	int a;
	int *ptr1 = &a;
        int **ptr2 = &ptr1;
        int ***ptr3 = &ptr2;
        int ****ptr4 = &ptr3;
        int *****ptr5 = &ptr4;
        int ******ptr6 = &ptr5;
        int *******ptr7 = &ptr6;
        int ********ptr8 = &ptr7;
        int *********nbr = &ptr8;
	char c;

	a = 0;
	c = a + '0';
	write(1, &c, 1);
	ft_ft(nbr);
	c = a / 10 + '0';
	write(1, &c, 1);
	c = a % 10 + '0';
	write(1, &c, 1);
}
