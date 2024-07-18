/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:23:53 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 15:31:00 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tail_params
{
	int		*files_to_read;
	int		*bytes_to_read;
	int		flag_c;
}	t_tail_params;

void	print_error_dir(char *str, char *prog_name, int files_to_read);
void	ft_putstr(char *str, int output);
int		ft_atoi(char *str);
void	ft_tail(char *str, t_tail_params *params, int i, char *prog_name);
void	print_error(char *str, char *prog_name);
void	print_name(char *str);
void	print_ten(char *file, int file_size);
void	print_n_bytes(char *file, int bytes_to_read, int file_size);
int		print_missing_arg(void);
int		print_invalid_bytes(char *str);
char	**check_flag_c(char **argv, t_tail_params *params);

#endif
