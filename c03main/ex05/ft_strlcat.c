/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:23:25 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 09:13:16 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	print_char(char c)
{
	write(1, &c, 1);
}

int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int 	j;
	unsigned int	dest_l;
	unsigned int	src_l;

	while (dest[dest_l] != '\0')
		dest_l++;
	while (src[src_l] != '\0')
		src_l++;
	if (size <= dest_l)
		return (src_l + size);
	i = dest_l;
	j = 0;
	while (i < (size - 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest_l + src_l);
}

int	main(void)
{
	char	src[] = "Hei";
	char	dest[12] = "World";
	int		a;

	a = strlcat(dest, src, 7);
//	a = ft_strlcat(dest, src, 12);
	if (a < 10)
	{
		print_char(a + '0');
	}
	else if (a > 9)
	{
		print_char(a / 10 + '0');
		print_char(a % 10 + '0');
	}
	print_char('\n');
	print_str(dest);
	return (0);
}
