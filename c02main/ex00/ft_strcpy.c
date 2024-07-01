/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:53:39 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 13:48:56 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	main(void)
{
	char	src[6] = "Testi";
	char	dest[6];
	char	*ptr;

	ptr = ft_strcpy(dest, src);
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr = ptr + 1;
	}
}
