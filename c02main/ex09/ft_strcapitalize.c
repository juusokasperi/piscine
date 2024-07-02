/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 13:09:39 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	not_alpha;

	i = 0;
	not_alpha = 1;
	while (str[i] != '\0')
	{
		if (not_alpha && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if (!not_alpha && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a'))
			not_alpha = 1;
		else
			not_alpha = 0;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "hELLO";
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strcapitalize(str);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
