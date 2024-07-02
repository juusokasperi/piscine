/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:23:25 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 16:54:29 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <bsd/string.h>

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
	unsigned int	j;

	i = 0;
	j = 0;

	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	if (size > i - 1)
		return (j + size);

	print_char(i + '0');
	return (0);
}

int	main(void)
{
	char	src[] = "Hei";
	char	dest[6] = "Worl";
	int		a;

//	a = strlcat(dest, src, 3);
	a = ft_strlcat(dest, src, 3);
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
