/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:49:49 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/12 13:17:51 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_display_file(char *str)
{
	char	buffer[1];
	int		file_descriptor;
	int		nb_read;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(file_descriptor, buffer, 1);
		if (nb_read == -1)
			return (0);
		ft_putchar(buffer[0]);
		buffer[nb_read] = '\0';
	}
	close(file_descriptor);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error: Usage ./ft_display_file <file_to_read>\n", 46);
		return (1);
	}
	if (ft_display_file(argv[1]))
		return (0);
	else
		return (1);
}
