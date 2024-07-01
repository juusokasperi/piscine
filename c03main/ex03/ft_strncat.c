/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:14:19 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 07:27:00 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	if (src[0] == '\0')
		return (dest);
	i = 0;
	j = 0;
	while (i < nb && src[i] != '\0')
	{
		while (dest[j] != '\0')
			j++;
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	main(void)
{
	char	src[] = "World";
	char	dest[100] = "Hello";
	char	*ptr;

	ptr = ft_strncat(dest, src, 5);
	printf("%s\n", ptr);
	return (0);
}
