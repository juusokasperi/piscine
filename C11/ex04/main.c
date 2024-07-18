/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:34 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/18 11:31:29 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_strcmp(int a, int b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

int	main(void)
{
	int	sorted_array[5] = {0, 1, 2, 3, 4};
	int	not_sorted[5] = {1, 3, 4, 5, 2};
	int	i;

	i = ft_is_sort(sorted_array, 5, &ft_strcmp);
	i = ft_is_sort(not_sorted, 5, &ft_strcmp);
}
