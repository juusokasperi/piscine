/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:37:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 19:12:48 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	handle_no_arguments(int bytes_to_read)
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
	if (bytes_to_read)
		print_n_bytes(store, bytes_to_read, len);
	else
		print_ten(store, len);
}

void	free_files(char ***files, int files_to_read)
{
	int	i;

	i = 0;
	while (i < files_to_read)
	{
		free((*files)[i]);
		i++;
	}
	free(*files);
}

int	main(int argc, char **argv)
{
	int				i;
	t_tail_params	params;
	char			**files;

	params.files_to_read = argc - 1;
	files = check_flag_c(argv, &params);
	if (params.files_to_read == 0 && params.bytes_to_read)
	{
		handle_no_arguments(params.bytes_to_read);
		return (free_files(&files, params.files_to_read), 0);
	}
	else if ((!files[0] && params.files_to_read > 0)
		|| params.bytes_to_read == 0)
		return (free_files(&files, 1), 1);
	i = 0;
	while (i < params.files_to_read)
	{
		ft_tail(files[i], &params, i, argv[0]);
		i++;
	}
	return (free_files(&files, params.files_to_read), 0);
}
