/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:31:00 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/28 22:12:55 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
		if (src[i] == '\0' && i < n)
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
	}
}

int	main(void)
{
	char	src[10] = "Testingia";
	char	dest[15] = "TestingiaTest";
	int	n;
	int	i;
	char	c;

	n = 14;
	i = 0;
	ft_strncpy(dest, src, n);
	while (i <= n)
	{
		write(1, &dest[i], 1);
		i++;
	}
}
