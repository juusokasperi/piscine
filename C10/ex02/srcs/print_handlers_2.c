/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:38:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 21:20:51 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_missing_arg(char *prog_name)
{
	ft_putstr(prog_name, 2);
	ft_putstr(": option requires an argument -- 'c'\n", 2);
	ft_putstr("Try 'tail --help' for more information.\n", 2);
	return (1);
}

int	print_invalid_bytes(char *str, char *prog_name)
{
	ft_putstr(prog_name, 2);
	ft_putstr(": invalid number of bytes: '", 2);
	ft_putstr(str, 2);
	ft_putstr("'\n", 2);
	return (1);
}

void	ft_putstr(char *str, int output)
{
	while (*str != '\0')
		write(output, str++, 1);
}
