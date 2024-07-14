/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/14 12:06:05 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char *read_chunk(int fd, int *nb_read)
{
    char buffer[4096];
    char *chunk;
    int i;

    *nb_read = read(fd, buffer, 4096);
    if (*nb_read <= 0)
        return NULL;
    chunk = (char *)malloc(*nb_read);
    for (i = 0; i < *nb_read; i++)
        chunk[i] = buffer[i];
    return chunk;
}

char *append_chunk(char *store, char *chunk, int store_len, int chunk_len)
{
    char *new_store;
    int i, j;

    new_store = (char *)malloc(store_len + chunk_len);
    for (i = 0; i < store_len; i++)
        new_store[i] = store[i];
    for (j = 0; j < chunk_len; j++)
        new_store[store_len + j] = chunk[j];
    free(store);
    free(chunk);
    return new_store;
}

char *read_file(int fd, int *size)
{
    char *store = NULL;
    char *chunk;
    int store_len = 0;
    int chunk_len;

    while (1)
    {
        chunk = read_chunk(fd, &chunk_len);
        if (!chunk)
            break;
        store = append_chunk(store, chunk, store_len, chunk_len);
        store_len += chunk_len;
    }
    *size = store_len;
    return store;
}

char *display_file(char *str, int *size, int argc)
{
    int file_descriptor;
    char *content;

    file_descriptor = open(str, O_RDONLY);
    if (file_descriptor == -1)
        return NULL;
    if (argc > 2)
        print_name(str);
    content = read_file(file_descriptor, size);
    close(file_descriptor);
    return content;
}

void	ft_tail(char *str, int bytes_to_read, int i, int argc)
{
	int		file_size;
	char	*file;

	file = display_file(str, &file_size, argc);
	if (errno)
		print_error(str);
	else if (bytes_to_read)
		print_n_bytes(file, bytes_to_read, file_size);
	else
		print_ten(file, file_size);
	if (i < argc - 1)
		write(1, "\n", 1);
}

// tarvitaan funktio joka tsekkaa onko argv:ssa -c flagi,
// jos on niin sita seuraavalle stringille tehdaan atoi
// ja niita kahta stringia ei laheteta tail -funktiolle

// display_file funktio pitais jotenkin jakaa osiin,
// esim; 1. read_file jossa homma yhdistyy
// 2. read_buffer jossa luetaan patka koodia
// 3. append, jossa yhdistetaan kaikki

/*
char	*display_file(char *str, int *size, int argc)
{
	char	*store;
	char	*temp_store;
	char	buffer[4096];
	int		file_descriptor;
	int		nb_read;
	int		len;
	int		i;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
	{
		return (0);
	}
	if (argc > 2)
		print_name(str);
	nb_read = -1;
	len = 0;
	i = 0;
	store = 0;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 4096);
		if (nb_read == -1)
		{
			return (0);
		}
		temp_store = (char *)malloc(len + nb_read);
		i = 0;
		while (i < len)
		{
			temp_store[i] = store[i];
			i++;
		}
		i = 0;
		while (i < nb_read)
		{
			temp_store[len + i] = buffer[i];
			i++;
		}
		free(store);
		store = temp_store;
		len += nb_read;
	}
	close(file_descriptor);
	*size = len;
	return (store);
}
*/
