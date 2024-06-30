/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:09:30 by jrinta-           #+#    #+#             */
/*   Updated: 2024/06/30 18:40:19 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str);

void	main(void)
{
	char	*str;

	str = "Coucou\ntu\tvas bien ?";
	ft_putstr_non_printable(str);
}
