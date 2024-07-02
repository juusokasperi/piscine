/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:27:06 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 18:37:55 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function appends src string to dest string, overwriting the terminating
// null byte at the end of dest and then adds a terminating null at the end.
// Dest must have enough space, otherwise behavior is unpredictable.

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	src[] = " Testing copying.";
	char	dest[60] = "Test.";
	char	*ptr;

	ptr = ft_strcat(dest, src);
	printf("%s\n", ptr);
	return (0);
}
