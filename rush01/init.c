/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:12:56 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 19:18:41 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_puzzle(char puzzle[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			puzzle[row][col] = '0';
			col++;
		}
		row++;
	}
}

int	check_clues(char *clues, int argc)
{
	int	clues_len;
	int	i;

	clues_len = 0;
	i = 0;
	if (argc != 2)
		return (0);
	while (clues[i] != '\0')
	{
		clues_len++;
		i++;
	}
	if (clues_len != 31)
		return (0);
	i = 0;
	while (i < 29)
	{
		if (!(clues[i] >= '1' && clues[i] <= '4') || (clues[i + 1] != ' ')
			|| !(clues[30] >= '1' && clues[30] <= '4'))
			return (0);
		i = i + 2;
	}
	return (1);
}

int	init(char puzzle[4][4], char *clues, int argc)
{
	fill_puzzle(puzzle);
	if (check_clues(clues, argc))
		return (1);
	else
		return (0);
}
