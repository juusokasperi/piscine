/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:31:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:48:40 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "0123456789a";
	b = ft_str_is_numeric(str);
	c = b + '0';
	write(1, &c, 1);
	return (0);
}
