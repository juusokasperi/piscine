/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:38:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 14:20:53 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_missing_arg(void)
{
	ft_putstr("tail: option requires an argument -- 'c'\n");
	ft_putstr("Try 'tail --help' for more information.\n");
	return (1);
}

int	print_invalid_bytes(char *str)
{
	ft_putstr("tail: invalid number of bytes: '");
	ft_putstr(str);
	ft_putstr("'\n");
	return (1);
}
