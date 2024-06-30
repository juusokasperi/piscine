/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:47:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 19:10:15 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

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
