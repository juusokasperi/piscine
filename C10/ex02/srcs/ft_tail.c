/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 20:10:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*read_part(int fd, int *nb_read)
{
	char	buffer[4096];
	char	*part;
	int		i;

	i = 0;
	*nb_read = read(fd, buffer, 4096);
	if (*nb_read <= 0)
		return (0);
	part = (char *)malloc(*nb_read);
	while (i < *nb_read)
	{
		part[i] = buffer[i];
		i++;
	}
	return (part);
}

char	*append_part(char *content, char *content_part,
	int content_len, int part_len)
{
	char	*new_content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_content = (char *)malloc(content_len + part_len);
	while (i < content_len)
	{
		new_content[i] = content[i];
		i++;
	}
	while (j < part_len)
	{
		new_content[content_len + j] = content_part[j];
		j++;
	}
	free(content);
	free(content_part);
	return (new_content);
}

char	*fetch_file(char *str, int *size)
{
	int		file_descriptor;
	char	*content;
	char	*content_part;
	int		content_len;
	int		part_len;

	content = 0;
	content_len = 0;
	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	while (1)
	{
		content_part = read_part(file_descriptor, &part_len);
		if (!content_part)
			break ;
		content = append_part(content, content_part, content_len, part_len);
		content_len += part_len;
	}
	free(content_part);
	*size = content_len;
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
	file = fetch_file(str, &file_size);
	if (i != 0
		&& ((previous_errno && !errno) || (!previous_errno && !errno)
			|| (previous_errno && errno == 21)))
		write(1, "\n", 1);
	if (errno == 21)
		print_error_dir(str);
	else if (errno)
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
	free(file);
}
