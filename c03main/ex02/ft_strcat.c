/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:14:19 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 19:33:51 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	
	if (src[0] == '\0')
		return (dest);
	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		while (dest[j] != '\0')
			j++;
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return(dest);
}

int	main(void)
{
	char src[] = "";
	char dest[100] = "Destination.";
	char	*ptr;

	ptr = ft_strcat(dest, src);
	printf("%s\n", ptr);
	return (0);
}
