/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:35:23 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 11:14:40 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

void	*fill_zeros(char *str);
void	str_copy(char *dest, char *src, int nb_read);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	print_error(char *str);
void	print_row(char *buffer, int offset, int nb_read);
void	write_address(int offset);

typedef struct s_file_info
{
	char	buffer[16];
	char	prev_buffer[16];
	int		file_descriptor;
	int		nb_read;
	int		offset;
}	t_file_info;

#endif
