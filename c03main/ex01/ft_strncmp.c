/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:31:18 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 13:45:05 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (i == n - 1)
			return (s1[i] - s2[i]);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	str1[] = "testi";
	char	str2[] = "testy";
	int		i;

	i = ft_strncmp(str1, str2, 20);
	printf("%d\n", i);
	return (0);
}
