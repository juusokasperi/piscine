#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define DEFAULT_BYTES 1000  // Roughly 10 lines at 100 chars each

void ft_putstr(int fd, char *str)
{
    while (*str)
        write(fd, str++, 1);
}

char *read_entire_file(const char *filename, size_t *file_size)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr(2, basename((char *)filename));
        ft_putstr(2, ": ");
        ft_putstr(2, strerror(errno));
        ft_putstr(2, "\n");
        return NULL;
    }

    char *buffer = NULL;
    size_t total_read = 0;
    ssize_t bytes_read;
    char temp_buffer[BUFFER_SIZE];

    while ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
    {
        char *new_buffer = malloc(total_read + bytes_read);
        if (!new_buffer)
        {
            free(buffer);
            close(fd);
            return NULL;
        }

        // Copy old buffer to new buffer
        for (size_t i = 0; i < total_read; i++)
            new_buffer[i] = buffer[i];

        // Copy new data to buffer
        for (ssize_t i = 0; i < bytes_read; i++)
            new_buffer[total_read + i] = temp_buffer[i];

        free(buffer);
        buffer = new_buffer;
        total_read += bytes_read;
    }

    close(fd);

    if (bytes_read == -1)
    {
        free(buffer);
        return NULL;
    }

    *file_size = total_read;
    return buffer;
}

int tail(const char *filename, long bytes)
{
    size_t file_size;
    char *file_content = read_entire_file(filename, &file_size);
    if (!file_content)
        return 1;

    size_t start = (bytes >= file_size) ? 0 : file_size - bytes;
    write(1, file_content + start, file_size - start);

    free(file_content);
    return 0;
}

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_putstr(2, "Usage: ");
        ft_putstr(2, basename(argv[0]));
        ft_putstr(2, " [-c bytes] filename\n");
        return 1;
    }

    long bytes = DEFAULT_BYTES;
    const char *filename = argv[1];

    if (argc >= 4 && argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
    {
        bytes = ft_atoi(argv[2]);
        filename = argv[3];
    }

    return tail(filename, bytes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:30:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/13 22:54:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
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
