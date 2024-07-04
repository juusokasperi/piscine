/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:04 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 21:15:34 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Arrange string array in alphabetical order (strncmp). Discard argv[0].
// One way is to iterate through the array one by one until you reach
// the end.

// First sort the strings, removing the first argument (program name).
// Add a if check to the main!

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort_array(int nbr, char **str)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < nbr)
	{
		j = i;
		while (j > 0 && ft_strcmp(str[j - 1], str[j]) > 0)
		{
			temp = str[j - 1];
			str[j - 1] = str[j];
			str[j] = temp;
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort_array(argc - 1, argv + 1);
	i = 0;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
