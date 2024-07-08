/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:49:47 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/08 17:30:25 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nbr_is_valid(char puzzle[4][4], int row, int col, char nbr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (puzzle[row][i] == nbr || puzzle[i][col] == nbr)
			return (0);
		i++;
	}
	return (1);
}

char	count_row(char puzzle[4][4], int row, int reverse)
{
	int	i;
	int	height;
	int	visible;
	int	count;

	count = '0';
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (reverse)
			height = puzzle[row][3 - i];
		else
			height = puzzle[row][i];
		if (height > visible)
		{
			visible = height;
			count++;
		}
		i++;
	}
	return (count);
}

char	count_col(char puzzle[4][4], int col, int reverse)
{
	int	i;
	int	height;
	int	visible;
	int	count;

	i = 0;
	count = '0';
	visible = 0;
	while (i < 4)
	{
		if (reverse)
			height = puzzle[3 - i][col];
		else
			height = puzzle[i][col];
		if (height > visible)
		{
			visible = height;
			count++;
		}
		i++;
	}
	return (count);
}

int	check_puzzle(char puzzle[4][4], char *clues)
{
	int	i;
	int	row_iterator;
	int	col_iterator;

	i = 0;
	col_iterator = 0;
	row_iterator = 16;
	while (i < 4)
	{
		if (count_row(puzzle, i, 0) != clues[row_iterator]
			|| count_row(puzzle, i, 1) != clues[row_iterator + 8])
			return (0);
		if (count_col(puzzle, i, 0) != clues[col_iterator]
			|| count_col(puzzle, i, 1) != clues[col_iterator + 8])
			return (0);
		i++;
		col_iterator += 2;
		row_iterator += 2;
	}
	return (1);
}

int	solve(char puzzle[4][4], char *clues, int row, int col)
{
	char	nbr;

	if (row == 4)
		return (check_puzzle(puzzle, clues));
	if (col == 4)
		return (solve(puzzle, clues, row + 1, 0));
	nbr = '1';
	while (nbr <= '4')
	{
		if (nbr_is_valid(puzzle, row, col, nbr))
		{
			puzzle[row][col] = nbr;
			if (solve(puzzle, clues, row, col + 1))
				return (1);
		}
		puzzle[row][col] = '0';
		nbr++;
	}
	return (0);
}
