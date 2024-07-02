/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 18:39:57 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strstr finds the first occurrence of str2 in str1 an

#include <unistd.h>
#include <stdio.h>

void	print_str(char *ptr)
{
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr++;
	}
}

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = "Test Sentence Starts Here.";
	str2 = "art";
	ptr = ft_strstr(str1, str2);
	printf("%s \n", ptr);
	return (0);
}
