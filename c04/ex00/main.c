/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:03:25 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 20:43:04 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		printf("ERROR: Invalid input");
		return (1);
	}
	str = argv[1];
	i = ft_strlen(str);
	printf("Length of str is: %i", i);
	return (0);
}
