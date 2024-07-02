/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:41:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 16:32:11 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strlcpy will always try to copy size - 1 (so null is included in the size
// sent to the function as a paremeter.

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[j] != '\0')
		j++;
	if (size > 0)
	{
		while (i < size - 1)
		{
			if (i < j && src[i] != '\0')
				dest[i] = src[i];
			else
				dest[i] = '\0';
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

int	main(void)
{
	char			src[] = "Hello";
	char			dest[35];
	unsigned int	a;
	int				i;

	i = 0;
	a = ft_strlcpy(dest, src, 5);
	if (a > 9)
	{
		write(1, "L: ", 3);
		print_char((a / 10) + '0');
		print_char((a % 10) + '0');
	}
	if (a < 10)
	{
		write(1, "L: ", 3);
		print_char(a + '0');
	}
	write(1, "\n", 1);
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
