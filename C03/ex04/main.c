/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:11 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 21:51:55 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Strstr finds the first occurrence of str2 in str1 an

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = "Test Sentence Starts Here.";
	str2 = "Art";
	ptr = ft_strstr(str1, str2);
	printf("%s \n", ptr);
	return (0);
}
