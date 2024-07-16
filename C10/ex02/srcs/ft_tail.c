/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 14:20:45 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*read_chunk(int fd, int *nb_read)
{
	char	buffer[4096];
	char	*chunk;
	int		i;

	i = 0;
	*nb_read = read(fd, buffer, 4096);
	if (*nb_read <= 0)
		return (0);
	chunk = (char *)malloc(*nb_read);
	while (i < *nb_read)
	{
		chunk[i] = buffer[i];
		i++;
	}
	return (chunk);
}

char	*append_chunk(char *store, char *chunk, int store_len, int chunk_len)
{
	char	*new_store;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_store = (char *)malloc(store_len + chunk_len);
	while (i < store_len)
	{
		new_store[i] = store[i];
		i++;
	}
	while (j < chunk_len)
	{
		new_store[store_len + j] = chunk[j];
		j++;
	}
	free(store);
	free(chunk);
	return (new_store);
}

char	*read_file(int fd, int *size)
{
	char	*store;
	char	*chunk;
	int		store_len;
	int		chunk_len;

	store = 0;
	store_len = 0;
	while (1)
	{
		chunk = read_chunk(fd, &chunk_len);
		if (!chunk)
			break ;
		store = append_chunk(store, chunk, store_len, chunk_len);
		store_len += chunk_len;
	}
	*size = store_len;
	return (store);
}

char	*display_file(char *str, int *size)
{
	int		file_descriptor;
	char	*content;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	content = read_file(file_descriptor, size);
	close(file_descriptor);
	return (content);
}

void	ft_tail(char *str, int bytes_to_read, int i, int files_to_read)
{
	int		file_size;
	char	*file;
	int		previous_errno;

	previous_errno = errno;
	errno = 0;
	file = display_file(str, &file_size);
	if (i != 0
		&& ((previous_errno && !errno) || (!previous_errno && !errno)))
		write(1, "\n", 1);
	if (errno)
		print_error(str);
	else
	{
		if (files_to_read > 1 && !errno)
			print_name(str);
		if (bytes_to_read)
			print_n_bytes(file, bytes_to_read, file_size);
		else
			print_ten(file, file_size);
	}
}
