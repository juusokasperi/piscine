/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 10:26:16 by jrinta-          ###   ########.fr       */
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

char *display_file(char *str, int *size, int files_to_read)
{
    int file_descriptor;
    char *content;

    file_descriptor = open(str, O_RDONLY);
    if (file_descriptor == -1)
        return (0);
    if (files_to_read > 1)
        print_name(str);
    content = read_file(file_descriptor, size);
    close(file_descriptor);
    return (content);
}

void	ft_tail(char *str, int bytes_to_read, int i, int files_to_read)
{
	int		file_size;
	char	*file;
    (void)i;

	file = display_file(str, &file_size, files_to_read);
	if (errno)
		print_error(str);
    else if (bytes_to_read)
		print_n_bytes(file, bytes_to_read, file_size);
	else
		print_ten(file, file_size);
	if (i < files_to_read - 1 && !errno)
		write(1, "\n", 1);
    errno = 0;
}
/*
Nyt probleema on seuraava:

tail test esa housu srcs/ft_atoi.c
==> test <==
test
tail: cannot open 'esa' for reading: No such file or directory
tail: cannot open 'housu' for reading: No such file or directory

==> srcs/ft_atoi.c <==
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (s * atoi);
}

./ft_tail test esa housu srcs/ft_atoi.c
==> test <==
test

tail: cannot open 'esa' for reading: No such file or directory
tail: cannot open 'housu' for reading: No such file or directory
==> srcs/ft_atoi.c <==
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (s * atoi);
}

Eli jos avatun filen jalkeinen seuraava file ei ole avattavissa, loppuun ei tule valia..
Ja jos failatun filen jalkeen tulee taas tiedosto, mita loytyy,, tulee newline.
*/
