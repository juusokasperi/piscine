/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:35:23 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/17 16:41:00 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

void	*fill_zeros(char *str);
void	str_copy(char *dest, char *src, int nb_read);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	print_error(char *str);
void	print_row(char *buffer, int offset, int nb_read);
void	write_address(int offset, int last);
char	**check_flag_c(char **argv, int *argc);

typedef struct s_file_info
{
	char	buffer[16];
	char	prev_buffer[16];
	int		fd;
	int		nb_read;
	int		offset;
	int		partial_size;
}	t_file_info;

#endif
