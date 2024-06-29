/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:41:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/29 19:00:53 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (src[i] != '\0')
	{
		while (i > size)
		{
			dest[i] = src[i];
			i++;
			l++;
		}
		if (i - 1 == size)
		{
			dest[i] = '\0';
		}
		l++;
		i++;
		
	}
	return(l);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	src[] = "Testi.";
	char	dest[3];
	unsigned int	a;

	a = ft_strlcpy(dest, src, 3);
	
	write(1, src, 7);

//	print_char(a + '0');
//	return (0);
}
