/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:02:14 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/01 16:23:47 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= ' '))
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

	str = "\n";
	b = ft_str_is_printable(str);
	c = b + '0';
	write(1, &c, 1);
}
