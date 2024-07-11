/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:33:02 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:51:01 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	*str;
	int	b;
	char	c;

	str = "\n";
	b = ft_str_is_printable(str);
	c = b + '0';
	write(1, &c, 1);
	return (0);
}
