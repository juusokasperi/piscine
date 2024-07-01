/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 14:24:51 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			&& ((str[p] >= '0' && str[p] <= '9')
				|| (str[p] >= 'a' && str[p] <= 'z')
				|| (str[p] >= 'A' && str[p] <= 'Z')))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
