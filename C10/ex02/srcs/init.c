/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:22:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 11:11:28 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	has_flag_c(char *str, int i)
{
	if (str[0] == '-' && str[1] == 'c'
		&& str[2] == '\0')
		return (i);
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
#include <stdio.h>
int	init(char ***files, char **argv, int *files_to_read, int *bytes_to_read, int flag_c)
{
	int	error;

	if (flag_c == -1)
		return (1);
	error = 0;
	if (flag_c == *files_to_read)
		error = print_missing_arg();
	else
	{
		*bytes_to_read = ft_atoi(argv[flag_c + 1]);
		if (*bytes_to_read == -1)
			error = print_invalid_bytes(argv[flag_c + 1]);
	}
	if (error)
	{
		*files = (char **)malloc(1 * sizeof(char *));
		(*files)[0] = 0;
		*files_to_read -= 2;
		return (0);
	}
	*files_to_read -= 2;
	return (1);
}

char	**fill_files(char **argv, int *files_to_read, int *bytes_to_read, int flag_c)
{
	char	**files;
	int		i;
	int		j;
	int		y;

	if (!init(&files, argv, files_to_read, bytes_to_read, flag_c))
		return (files);
	files = (char **)malloc((*files_to_read) * sizeof(char *));
	i = 1;
	y = 0;
	while (argv[i])
	{
		j = 0;
		if (i == flag_c)
			i += 2;
		if (!argv[i])
			break;
		while (argv[i][j])
			j++;
		files[y] = (char *)malloc((j + 1) * sizeof(char *));
		files[y] = ft_strcpy(files[y], argv[i]);
		i++;
		y++;
	}
	return (files);
}

char	**check_flag_c(char **argv, int *files_to_read, int *bytes_to_read)
{
	int	i;
	int	flag_c;

	*bytes_to_read = 0;
	i = 0;
	flag_c = -1;
	while (i <= *files_to_read)
	{
		flag_c = has_flag_c(argv[i], i);
		if (flag_c >= 0)
			break;
		i++;
	}
	return (fill_files(argv, files_to_read, bytes_to_read, flag_c));
}
