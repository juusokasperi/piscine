/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:49:49 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/14 09:04:40 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_display_file(char *str)
{
	char	buffer[1024];
	int		file_descriptor;
	int		nb_read;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 1024);
		if (nb_read == -1)
			return (0);
		write(1, buffer, nb_read);
	}
	close(file_descriptor);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	if (ft_display_file(argv[1]))
		return (0);
	else
	{
		write(1, "Cannot read file.\n", 18);
		return (1);
	}
}
