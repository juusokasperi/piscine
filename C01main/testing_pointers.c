/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_pointers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:57:49 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/27 19:05:02 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_ft(int *nbr)
{
	char c;
	*nbr = 42;
}


int	main(void)
{
	int a;
	int *nbr;
	char c;

	nbr = &a;

	a = 1;
	
	ft_ft(nbr);
	c = a / 10 + '0';
        write(1, &c, 1);
        c = a % 10 + '0';
        write(1, &c, 1);

	/*	
	*nbr = 10;
	c = *nbr / 10 + '0';
	write(1, &c, 1);
	c = *nbr % 10 + '0';
	write(1, &c, 1);
*/
}
