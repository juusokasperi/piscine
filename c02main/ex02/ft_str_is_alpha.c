/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 16:16:39 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if(!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);
		str = str + 1;
	}
	return (1);
}

void	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "abcdefgh123";
	b = ft_str_is_alpha(str);
	c = b + '0';
	write(1, &c, 1);
}
