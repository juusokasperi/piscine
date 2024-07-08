/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 05:53:25 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/08 11:49:27 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(int argc, char **argv)
{
	char	*dup;

	if (argc != 2)
	{
		printf("ERROR - Usage \"%s <str_to_duplicate>\"\n", argv[0]);
		return (1);
	}
	dup = ft_strdup(argv[1]);
	printf("Strdup is: %s\n", dup);
	free (dup);
	printf("After running free() strdup is: %s", dup);
	return (0);
}
