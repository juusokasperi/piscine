/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:31:13 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/11 19:03:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	int	start;
	int length;
	int count_substr;
	char **array;
	int arr_i;
	int	x;

	count_substr = 0;
	length = ft_strlen(charset);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || is_separator(str[i - 1], charset, length))
			if (!is_separator(str[i], charset, length))
				count_substr++;
		i++;
	}
	array = malloc((count_substr + 1) * sizeof(char));
	if (!array)
		return (0);
	arr_i = 0;
	start = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (is_separator(str[j], charset, length))
		{
			if (!str)
				return (0);
			array[arr_i] = malloc(i - start + 1);
			array[arr_i] = ft_strlcpy(array[arr_i], &str[start], j - start + 1);
			i = j;
			arr_i++;
			start = i;
		}
		i++;
	}
	return (array);
}

// Nyt se printtaa stringit muuten, mutta ei ota viela huomioon tilannetta,
// jossa string ei lopu separaattoriin. Eli esimerkkitilanteessa arraysta loytyy
// "H", "ello ", ja "Wo" mutta "ld" puuttuu.
// Ja ei toimi jos on perakkain monta separatoria.
// Chekkiin taytyy tehda etta asettaa startin vaan jos edellinen ollu separator
// mutta nykyinen ei. Jos edellinen separator ja nykyinenkin, mennaan eteenpain.

int	main(void)
{
	char	*str;
	char	*charset;
	char	**array;
	int		i;

	str = "Heeello World";
	charset = "eWr";
	array = ft_split(str, charset);
	i = 0;
	while (array[i])
	{
		printf("Array[%i] is %s\n", i, array[i]);
		i++;
	}
}
