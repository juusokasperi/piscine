/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:37:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/15 10:00:05 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	handle_no_arguments(void)
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
	return (0);
}

int	has_flag_c(char *str)
{
	if (str[0] == '-' && str[1] == 'c'
		&& str[2] == '\0')
		return (1);
	return (0);
}
#include <stdio.h>
char	**check_flag_c(char **argv, int *files_to_read, int *bytes_to_read)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (has_flag_c(argv[i]))
		{
			if (i == *files_to_read)
			{
				print_missing_arg();
				argv[0] = 0;
				return(argv);
			}
			*bytes_to_read = ft_atoi(argv[i + 1]);
			if (*bytes_to_read == -1)
			{
				print_invalid_bytes(argv[i + 1]);
				argv[0] = 0;
				return(argv);
			}
			*files_to_read -= 2;
			return (argv + 1);
		}
		i++;
	}
	return (argv + 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int bytes_to_read;
	int	files_to_read;
	char **files;

	files_to_read = argc - 1;
	bytes_to_read = 0;
	if (files_to_read == 0)
		return (handle_no_arguments());
	files = check_flag_c(argv, &files_to_read, &bytes_to_read);
	if (!files[0])
		return (1);
	i  = 0;
	if (files_to_read == 1)
	{
		if (has_flag_c(files[i]))
			i += 2;
		ft_tail(files[0], bytes_to_read, 0, files_to_read);
	}
	else
	{
		i = 0;
		while (i < files_to_read)
		{
			ft_tail(files[i], bytes_to_read, i, files_to_read);
			i++;
		}
	}
	return (0);
}

// jaa osiin, siisti koodia.
// lisaa muistin vapautus
