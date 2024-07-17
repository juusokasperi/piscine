/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:38:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 13:38:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_missing_arg(void)
{
	ft_putstr("tail: option requires an argument -- 'c'\n", 2);
	ft_putstr("Try 'tail --help' for more information.\n", 2);
	return (1);
}

int	print_invalid_bytes(char *str)
{
	ft_putstr("tail: invalid number of bytes: '", 2);
	ft_putstr(str, 2);
	ft_putstr("'\n", 2);
	return (1);
}

void	ft_putstr(char *str, int output)
{
	while (*str != '\0')
		write(output, str++, 1);
}
