/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:33:09 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 14:55:04 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	initialize(int puzzle[4][4], int clues[4][4], int argc, char **argv);

int	solve(int puzzle[4][4], int clues[4][4], int row, int col);

void	print_grid(int puzzle[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = puzzle[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	puzzle[4][4];
	int	clues[4][4];

	if (!initialize(puzzle, clues, argc, argv))
	{
		write(1, "Error: Invalid input.\n", 22);
		return (0);
	}
	if (solve(puzzle, clues, 0, 0))
		print_grid(puzzle);
	else
	{
		write(1, "No solution available.\n", 23);
	}
	return (0);
}

puzzle = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }
