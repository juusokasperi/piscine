/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:41:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 15:43:21 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (src[i] != '\0')
				dest[i] = src[i];
			else
				dest[i] = '\0';
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
