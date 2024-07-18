/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:32:18 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 12:24:45 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_doop.h"

int	ft_atoi(char *str);
void	ft_putnbr(int nb);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	check_operator(char *argv, char *operator)
{
	if (ft_strlen(argv) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[0] == '+' || argv[0] == '-' || argv[0] == '/'
		|| argv[0] == '*' || argv[0] == '%')
	{
		*operator = argv[0];
		return (1);
	}
	write(1, "0\n", 2);
	return (0);
}

int	handle_zero(char operator)
{
	if (operator == '%')
		write(1, "Stop : modulo by zero\n", 22);
	if (operator == '/')
		write(1, "Stop : division by zero\n", 24);
	return (1);
}

int	count_values(int value1, char operator, int value2)
{
	if (operator == '+')
		ft_putnbr(value1 + value2);
	if (operator == '-')
		ft_putnbr(value1 - value2);
	if (operator == '*')
		ft_putnbr(value1 * value2);
	if (operator == '/')
		ft_putnbr(value1 / value2);
	if (operator == '%')
		ft_putnbr(value1 % value2);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	value1;
	int	value2;
	char	operator;

	if (argc != 4)
		return (1);
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	if (!check_operator(argv[2], &operator))
		return (1);
	if ((operator == '/' || operator == '%') && value2 == 0)
		return (handle_zero(operator));
	return (count_values(value1, operator, value2));
}
