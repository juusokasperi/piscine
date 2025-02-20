/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:29:22 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:30:05 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies the string src to string dest. If no NULL terminator within the
// first n bytes of src, dest will not be null-terminated. If n is longer than
// src, additional null terminators will be written in the string dest.

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src[10] = "Testingia";
	char	dest[20];
	int	n;
	char	*c;


	n = 5;
	c = ft_strncpy(dest, src, n);
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}
