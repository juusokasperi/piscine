/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 13:40:25 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If str empty, returns str. First checks first character, if small, make big.
// Then start a while loop which iterates until it hits the null terminator.
// If i is lowercase and p is a symbol or space, transform to uppercase.
// If i is uppercase and p is a symbol or space or a character, transform to lowercase.
// If i is uppercase and p is not a character, transform to lowercase.

// if ((str[i] >= 'A' && str[i] <= 'Z')
//		&& !((str[p] >= 'a' && str[p] < 'z') || (str[p] >= 'A' && str[p] <= 'Z'))



#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	p;

	if (str[0] == '\0')
		return (str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		p = i - 1;
		if ((str[i] >= 'a' && str[i] <= 'z') 
			&& (str[p] < '0' || (str[p] > '9' && str[p] < 'A')
				|| (str[p] > 'Z' && str[p] < 'a')))
			str[i] = str[i] - 32;
		if ((str[i] >= 'A' && str[i] <= 'Z')
			&& ((str[p] >= '0' && str[p] <= '9') || (str[p] >= 'a' && str[p] <= 'z')
					|| (str[p] >= 'A' && str[p] <= 'Z')))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	main(void)
{
	char	str[] = 
		"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	char	str1[] = "hELLO hello Hello";
	char	str2[] = "HELLO";

	char	*a;
	char	*b;
	char	*c;

	a = ft_strcapitalize(str);
	b = ft_strcapitalize(str1);
	c = ft_strcapitalize(str2);
	write(1, a, 62);
	write(1, "\n", 1);
	write(1, b, 17);
	write(1, "\n", 1);
	write(1, c, 5);
}
