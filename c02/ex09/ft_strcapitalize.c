/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/29 18:30:01 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	p;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		p = i - 1;
		if (((str[i] >= 'a' && str[i] < 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
			&& (str[p] < '0' || (str[p] > '9' && str[p] < 'A')
				|| (str[p] > 'Z' && str[p] < 'a') || str[p] > 'z'))
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str [i] + 32;
		i++;
	}
	return (str);
}

void	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	*b;
	char	*c;
	char	str1[] = "HELLO";

	b = ft_strcapitalize(str);
	c = ft_strcapitalize(str1);
	write(1, b, 61);
	write(1, c, 5);
}
