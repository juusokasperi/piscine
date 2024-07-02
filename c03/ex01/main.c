/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:26:15 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 18:36:01 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 00 if equal, negative if s1 < s2, positive if s1 > s2

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	str1[] = "testj";
	char	str2[] = "testi";
	int		i;

	i = ft_strncmp(str1, str2, 5);
	printf("%d\n", i);

	return (0);
}
