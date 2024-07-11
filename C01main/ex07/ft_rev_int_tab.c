/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:34:45 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/29 12:51:26 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;

	i = 0;
	while(i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - (i + 1)];
		tab[size - (i + 1)] = temp;
		i++;
	}
}

void	main(void)
{
	int	tab[]= {0, 1, 2, 3, 4};
	char	c;

	ft_rev_int_tab(tab, 5);
	c = tab[0] + '0';
	write(1, &c, 1);
	c = tab[1] + '0';
        write(1, &c, 1);
	c = tab[2] + '0';
	write(1, &c, 1);
	c = tab[3] + '0';
        write(1, &c, 1);
	c = tab[4] + '0';
        write(1, &c, 1);

}
