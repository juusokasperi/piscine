/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:31:49 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:49:39 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "abcdA";
	b = ft_str_is_lowercase(str);
	c = b + '0';
	write(1, &c, 1);
	return (0);
}
