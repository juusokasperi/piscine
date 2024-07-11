/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:13:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/11 15:18:36 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char str[20] = "Hello World";
	char dest[20];
	char *c;

	c = ft_strncpy(dest, &str[6], 5);
	printf("%s", dest);
	return (0);
}
