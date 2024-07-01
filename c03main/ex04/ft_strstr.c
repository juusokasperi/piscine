/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:41:45 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 23:06:12 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *ptr)
{
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr++;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (&str[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*largestring;
	char	*smallstring;
	char	*ptr;

	largestring = "Foo Bar Baz";
	smallstring = "Esa";
	ptr = ft_strstr(largestring, smallstring);
	print_str(ptr);
}
