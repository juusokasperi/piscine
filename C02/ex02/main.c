/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:30:24 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:30:48 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

void	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "abcdefgABC";
	b = ft_str_is_alpha(str);
	c = b + '0';
	write(1, &c, 1);
}
