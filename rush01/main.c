/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:33:09 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 19:24:33 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	init(char puzzle[4][4], char *clues, int argc);

int	solve(char puzzle[4][4], char *clues, int row, int col);

void	print_grid(char puzzle[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			write(1, &puzzle[row][col], 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	main(int argc, char **argv)
{
	char	puzzle[4][4];
	char	*clues;

	clues = argv[1];
	if (!init(puzzle, clues, argc))
	{
		write(1, "Error: Invalid input.\n", 22);
		return (0);
	}
	if (solve(puzzle, clues, 0, 0))
		print_grid(puzzle);
	else
	{
		write(1, "No solution available.\n", 23);
		return (1);
	}
	return (0);
}
