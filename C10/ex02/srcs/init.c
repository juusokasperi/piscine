/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:22:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/16 14:20:34 by jrinta-          ###   ########.fr       */
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

int	init(char ***files, char **argv, t_tail_params *params)
{
	int	error;

	if (params->flag_c == -1)
		return (1);
	error = 0;
	if (params->flag_c == *(params->files_to_read))
		error = print_missing_arg();
	else
	{
		*(params->bytes_to_read) = ft_atoi(argv[params->flag_c + 1]);
		if (*(params->bytes_to_read) == -1)
			error = print_invalid_bytes(argv[params->flag_c + 1]);
	}
	if (error)
	{
		*files = (char **)malloc(1 * sizeof(char *));
		(*files)[0] = 0;
		*(params->files_to_read) -= 2;
		return (0);
	}
	*(params->files_to_read) -= 2;
	return (1);
}

char	**fill_files(char **argv, t_tail_params *params)
{
	char	**files;
	int		i;
	int		j;
	int		y;

	if (!init(&files, argv, params))
		return (files);
	files = (char **)malloc((*(params->files_to_read)) * sizeof(char *));
	i = 1;
	y = 0;
	while (argv[i])
	{
		j = 0;
		if (i == params->flag_c)
			i += 2;
		if (!argv[i])
			break ;
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
	int				i;
	t_tail_params	params;

	*bytes_to_read = 0;
	i = 0;
	params.flag_c = -1;
	params.files_to_read = files_to_read;
	params.bytes_to_read = bytes_to_read;
	while (i <= *files_to_read)
	{
		params.flag_c = has_flag_c(argv[i], i);
		if (params.flag_c >= 0)
			break ;
		i++;
	}
	return (fill_files(argv, &params));
}
