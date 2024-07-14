/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:37:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/14 12:05:30 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	handle_no_arguments(void)
{
	char	buffer[1024];
	char	store[2048];
	int		nb_read;
	int		len;
	int		i;

	len = 0;
	i = 0;
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(0, buffer, 1024);
		while (i < nb_read)
		{
			store[i + len] = buffer[i];
			i++;
		}
		len += nb_read;
		i = 0;
	}
	write(1, store, len);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
	{
		handle_no_arguments();
		return (0);
	}
	i = 1;
	if (argc == 2)
		ft_tail(argv[i], 90, i, argc);
	else
	{
		while (i < argc)
		{
			ft_tail(argv[i], 90, i, argc);
			i++;
		}
	}
	return (0);
}
