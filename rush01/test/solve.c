/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:49:47 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 14:43:46 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	nbr_is_valid(int puzzle[4][4], int row, int col, int nbr)
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

int	count_row(int puzzle[4][4], int row, int reverse)
{
	int	i;
	int	height;
	int	visible;
	int	count;

	count = 0;
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

int	count_col(int puzzle[4][4], int col, int reverse)
{
	int	i;
	int	height;
	int	visible;
	int	count;

	i = 0;
	count = 0;
	visible = 0;
	while (i < 4)
	{
		if (reverse)
			height = puzzle[4 - 1 - i][col];
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

int	check_puzzle(int puzzle[4][4], int clues [4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_row(puzzle, i, 0) != clues[2][i]
			|| count_row(puzzle, i, 1) != clues[3][i])
			return (0);
		if (count_col(puzzle, i, 0) != clues[0][i]
			|| count_col(puzzle, i, 1) != clues[1][i])
			return (0);
		i++;
	}
	return (1);
}

int	solve(int puzzle[4][4], int clues[4][4], int row, int col)
{
	int	i;

	if (row == 4)
		return (check_puzzle(puzzle, clues));
	if (col == 4)
		return (solve(puzzle, clues, row + 1, 0));
	i = 1;
	while (i <= 4)
	{
		if (nbr_is_valid(puzzle, row, col, i))
		{
			puzzle[row][col] = i;
			if (solve(puzzle, clues, row, col + 1))
				return (1);
		}
		puzzle[row][col] = 0;
		i++;
	}
	return (0);
}
