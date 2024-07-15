#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_tail(char *str, int bytes_to_read, int i, int argc);
void	print_error(char *str);
void	print_name(char *str);
void	print_ten(char *file, int file_size);
void	print_n_bytes(char *file, int bytes_to_read, int file_size);
void	print_missing_arg(void);
void	print_invalid_bytes(char *str);

#endif
