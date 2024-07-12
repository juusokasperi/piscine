/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:31:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/12 12:02:51 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i + 1], charset) == 1
				&& is_separator(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
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

void	fill_array(char **array, char *str, char *charset)
{
	int		i;
	int		j;
	int		cell;

	cell = 0;
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
			array[cell] = (char*)malloc((j + 1));
			copy_str(array[cell], str + i, charset);
			i = j + i;
			cell++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		array_cells;

	array_cells = count_substr(str, charset);
	array = (char**)malloc((array_cells + 1) * sizeof(char*));
	if (!array)
		return (0);
	fill_array(array, str, charset);
	array[array_cells] = 0;
	return (array);
}
