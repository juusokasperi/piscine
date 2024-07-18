/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:34:46 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 20:57:42 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);

int	main(int argc, char **argv)
{
//	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	int		i;

	(void)argc;
	i = 0;
	ft_strcapitalize(argv[1]);
	while (argv[1][i] != '\0')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	return (0);
}
