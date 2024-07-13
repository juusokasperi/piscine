/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/13 17:56:58 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_display_file(char *str)
{
	char	buffer[2];
	int		file_descriptor;
	int		nb_read;

	file_descriptor = open(str, O_RDONLY);
	printf("fd is %i\n", file_descriptor);
	if (file_descriptor == -1)
	{
		printf("Errno: %s\n", strerror(errno));
		return (0);
	}
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 1);
		if (nb_read == -1)
		{
			printf("Errno: %s\n", strerror(errno));
			return (0);
		}
		buffer[nb_read] = 0;
		ft_putstr(buffer);
	}
	close(file_descriptor);
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("argv1 is %s\nargv2 is %s\n", argv[0], argv[1]);
	ft_display_file(argv[1]);
	return (0);
}
