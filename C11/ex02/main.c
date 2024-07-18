/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:12:12 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 11:29:56 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*));

int	has_capital_b(char *str)
{
	while (*str)
	{
		if (*str == 'B')
			return (1);
		str++;
	}
	return (0);
}

int	main(void)
{
	char	*tab = "bbbtsx";
	int		i;

	i = ft_any(&tab, &has_capital_b);
}
