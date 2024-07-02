/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:34:19 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:55:25 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str[] = "abc!!!123!!!ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	ft_strlowcase(str);
	write(1, str, 38);
	return (0);
}
