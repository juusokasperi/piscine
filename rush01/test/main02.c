/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:33:09 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 11:22:26 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define N 4

int	initialize(int puzzle[N][N], int clues[4][N], int argc, char **argv);

int	solve(int puzzle[N][N], int clues[4][N], int row, int col);

void	print_grid(int puzzle[N][N])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
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
	int	puzzle[N][N];
	int	clues[4][N];

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
