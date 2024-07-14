/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:37:40 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/14 23:13:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	handle_no_arguments(void)
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
}
#include <stdio.h>

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

char	**check_flag_c(char **argv, int *files_to_read, int *bytes_to_read)
{
	int	i;
	int	j;
	int	y;
	int	flag_c;
	char	**files;

	*bytes_to_read = 0;
	i = 0;
	while (i < *files_to_read)
	{
		flag_c = has_flag_c(argv[i], i);
		if (flag_c >= 0)
			break;
		i++;
	}
	printf("has flag is %i\n", flag_c);
	printf("filestoread is %i\n", *files_to_read);
	if (flag_c >= 0)
	{
		*bytes_to_read = ft_atoi(argv[flag_c + 1]);
		*files_to_read -= 2;
		files = (char **)malloc((*files_to_read) * sizeof(char *));
		i = 1;
		y = 0;
		printf("flag_c is %i\n", flag_c);
		while (argv[i])
		{
			j = 0;
			if (i == flag_c)
				i += 2;
			if (!argv[i])
				break;
			while (argv[i][j])
				j++;
			printf("argv[i] is %s\n", argv[i]);
			files[y] = (char *)malloc((j + 1) * sizeof(char *));
			files[y] = ft_strcpy(files[y], argv[i]);
			printf("files[%i] is %s\n", y, files[y]);
			i++;
			y++;
		}
		return (files);
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
	printf("filestoread is %i\n", files_to_read);
	bytes_to_read = 0;
	if (files_to_read == 0)
	{
		handle_no_arguments();
		return (0);
	}
	files = check_flag_c(argv, &files_to_read, &bytes_to_read);
	i = 0;
	while (files[i])
	{
		printf("back in main, files[%i] is %s\n", i, files[i]);
		i++;
	}
	i = 0;
	printf("files_to_read is %i\n", files_to_read);
	if (files_to_read == 1)
	{
		printf("now going to ft_tail, sending files[i]: %s\n", files[i]);
		printf("bytes_to_read: %i\n", bytes_to_read);
		ft_tail(files[i], bytes_to_read, i, files_to_read);
	}
	else
	{
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
