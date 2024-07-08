/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:43:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/08 00:38:46 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *strs[5] = { "Hello", "how", "are", "you", "today?" };
	char *concat_string;
	char *sep;

	sep = ", ";
	concat_string = ft_strjoin(5, strs, sep);
	printf("Concat_string is: %s\n", concat_string);
	free(concat_string);
}
