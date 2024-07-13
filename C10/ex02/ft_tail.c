/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/13 19:44:20 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	print_error(char *str)
{
		ft_putstr("tail: cannot open '");
		ft_putstr(str);
		ft_putstr("' for reading: ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
}
void	print_name(char *str)
{
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==");
	ft_putstr("\n");
}
int	ft_display_file(char *str, int multiple)
{
	char	buffer[1024];
	int		file_descriptor;
	int		nb_read;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
	{
		print_error(str);
		return (0);
	}
	if (multiple)
		print_name(str);
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 1024);
		if (nb_read == -1)
		{
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
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	if (argc == 2)
		ft_display_file(argv[i], 0);
	else
	{
	while (i < argc)
		{
			ft_display_file(argv[i], 1);
			i++;
		}
	}
	return (0);
}
