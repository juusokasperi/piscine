/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:33:36 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/02 19:53:32 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	str[] = "1234ABCD !!00!! abcdefghijklmnopqrstuvwxyz";

	ft_strupcase(str);
	write(1, str, 42);
	return (0);
}
