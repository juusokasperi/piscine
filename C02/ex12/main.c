/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:47:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 08:18:56 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	address;
	char 			addr_to_hex[16];
	char 			hex_char[];
	int				i;

	address = (unsigned int) addr;
	i = 0;
	while (i < 16)
	{
		addr_to_hex[i] = '0'
		i++;
	}
	while (address > 0)
	{
		hex_char = "0123456789abcdef"
	}
}

int	main(void)
{
	char	str[] = "Bonjour les amin";
	char	dest[100];
	char	*ptr;

	ft_print_memory(str, 16);
	ptr = dest;
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr = ptr + 1;
	}
	return (0);
}
