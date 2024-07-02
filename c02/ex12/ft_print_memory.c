/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:45:16 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 19:11:01 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	int	i;

	i = 0;
	while(i <= 16)
	{
		write(1, %str, 16);
		str++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{	
	char	hex[16];
	
	print_str(addr);
}
