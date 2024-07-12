/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:30:58 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/12 10:31:57 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	**array;
	int		i;

	if (argc != 3)
	{
		printf("Error: Usage %s <string> <charset>\n", argv[0]);
		return (1);
	}
	array = ft_split(argv[1], argv[2]);
	i = 0;
	while (array[i])
	{
		printf("Array[%i] is %s\n", i, array[i]);
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	return (0);
}
