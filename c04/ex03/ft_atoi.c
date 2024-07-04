/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:17 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/04 06:09:35 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isspace(int arg)
{
	if (arg == ' ' || (arg >= 9 && arg <= 13))
		return (1);
	else
		return (0);
}

int	issign(int arg, int *sign)
{
	if (arg == '-' || arg == '+')
	{
		if ((*sign == -1 && arg == '-')
			|| (*sign == 1 && arg == '-'))
			*sign *= -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	atoi;

	s = 1;
	i = 0;
	atoi = 0;
	while (isspace(str[i]) && str[i] != '\0')
		i++;
	while (issign(str[i], &s) && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			atoi = (atoi * 10) + str[i] - '0';
		}
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	return (s * atoi);
}
