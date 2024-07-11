/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:27:53 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 18:28:09 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strncat similar to strcat, except that it:
// will use at most n bytes from src, and
// src doesn't need to be null-terminated, if src > n
// It will write n + 1, so it adds the null at the end.

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	src[] = "World";
	char	dest[100] = "Hello ";
	char	*ptr;

	ptr = ft_strncat(dest, src, 4);
	printf("%s\n", ptr);
	return (0);
}
