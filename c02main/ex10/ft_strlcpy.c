/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:41:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 13:39:00 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strlcpy will always try to copy size - 1 (so null is included in the size
// sent to the function as a paremeter.

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (i);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	src[] = "BABBAB";
	char	dest[10];
	unsigned int	a;

	a = ft_strlcpy(dest, src, 5);
	print_char(a + '0');
	return (0);
}
