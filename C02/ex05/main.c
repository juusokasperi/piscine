/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:32:17 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:50:16 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "ABCDEF";
	b = ft_str_is_uppercase(str);
	c = b + '0';
	write(1, &c, 1);
	return (0);
}

