/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:43:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 20:48:29 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *str1 = "String 1 X";
	char *str2 = "String 2 X";
	char *str3 = "String 3 X";
	char *strs = { str1, str2, str3 };

	printf("strs[0] is %s", strs[0]);
}
