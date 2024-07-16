/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:37:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 14:33:13 by jrinta-          ###   ########.fr       */
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
	int		i;
	int		bytes_to_read;
	int		files_to_read;
	char	**files;

	files_to_read = argc - 1;
	bytes_to_read = 0;
	if (files_to_read == 0)
		return (handle_no_arguments());
	files = check_flag_c(argv, &files_to_read, &bytes_to_read);
	if (!files[0])
		return (1);
	i = 0;
	if (files_to_read == 1)
		ft_tail(files[i], bytes_to_read, i, files_to_read);
	else
	{
		while (i < files_to_read)
		{
			ft_tail(files[i], bytes_to_read, i, files_to_read);
			i++;
		}
	}
	free_files(&files, files_to_read);
	return (0);
}

// tsekkaa esim talla:
// ./ft_tail -c 50 test srcs/ft_atoi.c esa srcs/ srcs/print_handlers.c
// tuleeko toi "srcs/" oikein, etta sanoo vaan No such file or directory, vai
// paaseeko se eteenpain ja printtaa sen file -headerin ja ilmottaa vasta sitten
// "Is directory"?

// muuten mun mielesta kaikki kunnossa, mutta initissa tarvii 5 argumenttia,
// joka on liikaa

// tarkista viela tail -c -50 srcs/ft_atoi.c -> miten printtaa jos miinus?
