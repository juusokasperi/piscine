/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:43:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/09 19:14:23 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	char	*concat_string;
	char	*sep;

	(void)argc;
	sep = ", ";
	concat_string = ft_strjoin(argc - 1, argv + 1, sep);
	printf("Concat_string is: %s\n", concat_string);
	free(concat_string);
	printf("After running free, concat_string is: %s\n", concat_string);
}
