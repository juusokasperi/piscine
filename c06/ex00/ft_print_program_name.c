/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:14:35 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 16:17:50 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *name)
{
	while (*name != '\0')
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
}

int	main(int c, char **argv)
{
	ft_print_program_name(argv[0]);
}
