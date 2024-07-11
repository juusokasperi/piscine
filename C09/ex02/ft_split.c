/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:31:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/11 23:23:45 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int		count_substr(char *str, char *charset)
{
	int	i;
	int	substr;

	substr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i + 1], charset) == 1
				&& is_separator(str[i], charset) == 0)
			substr++;
		i++;
	}
	return (substr);
}

void	copy_str(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_separator(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		substr;

	substr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(str[i + j], charset) == 0)
				j++;
			split[substr] = (char*)malloc((j + 1) * sizeof(char)  );
			copy_str(split[substr], str + i, charset);
			i += j;
			substr++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		substr;

	substr = count_substr(str, charset);
	array = (char**)malloc((substr + 1) * sizeof(char*));
	array[substr] = 0;
	write_split(array, str, charset);
	return (array);
}

int	main(void)
{
	char	*str;
	char	*charset;
	char	**array;
	int		i;

	str = "eHeeello World";
	charset = "eWr";
	array = ft_split(str, charset);
	i = 0;
	while (array[i])
	{
		printf("Array[%i] is %s\n", i, array[i]);
		i++;
	}
}
