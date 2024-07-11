/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:31:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/11 17:33:58 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
		dest[i] = '\0';
		i++;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int is_separator(char c, char *charset, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char **ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	int	last_separator;
	char *substr;
	int length;
	char **array;
	int array_i;
	int	x;

	length = ft_strlen(charset);
	i = 0;
	x = 0;
	array_i = 0;
	last_separator = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (is_separator(str[j], charset, length))
		{
			substr = malloc(j - i + 1);
			if (!str)
				return (0);
			substr = ft_strlcpy(substr, &str[last_separator], j - last_separator + 1);
			while (substr[x] != 0)
			{
				array[array_i][x] = substr[x]
				x++;
			}
			x = 0;
			i = j + 1;
			last_separator = i;
		}
		i++;
	}
	return (array);
}

int	main(void)
{
	char	*str;
	char	*charset;
	char	**array;

	str = "Hello World";
	charset = "eWr";
	array = ft_split(str, charset);
}
