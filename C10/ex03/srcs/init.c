/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:39:05 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 15:00:41 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	has_flag_c(char *str, int i)
{
	if (str[0] == '-' && str[1] == 'C'
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

int	init(char ***files, int flag_c, int *argc)
{
	if (flag_c == -1)
	{
		*files = (char **)malloc(1 * sizeof(char *));
		(*files)[0] = 0;
		return (0);
	}
	*argc = *argc - 1;
	return (1);
}

char	**fill_files(char **argv, int *argc, int flag_c)
{
	char	**files;
	int		i;
	int		j;
	int		y;

	if (!init(&files, flag_c, argc))
		return (files);
	files = (char **)malloc((*argc) * sizeof(char *));
	i = 1;
	y = 0;
	while (argv[i])
	{
		j = 0;
		if (i == flag_c)
			i++;
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

char	**check_flag_c(char **argv, int *argc)
{
	int	i;
	int	flag_c;

	i = 1;
	*argc = *argc - 1;
	flag_c = -1;
	while (i <= *argc)
	{
		flag_c = has_flag_c(argv[i], i);
		if (flag_c >= 0)
			break ;
		i++;
	}
	return (fill_files(argv, argc, flag_c));
}
