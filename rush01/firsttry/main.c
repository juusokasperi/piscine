/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:45:55 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 11:22:22 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define N 4

void	print_grid(int puzzle[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%d ", puzzle[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

// Tarkistetaan, onko numero jo samalla rivilla
// tai sarakkeella.

int	is_valid(int puzzle[N][N], int row, int col, int nbr)
{
	int x;

	x = 0;
	while (x < N)
	{
		if (puzzle[row][x] == nbr || puzzle[x][col] == nbr)
			return (0);
		x++;
	}
	return (1);
}

// Tsekataan rivia 1 2 3 4.
//

int count_visible_row(int puzzle[N][N], int row, int reverse)
{
	int count;
	int visible;
	int i;
	int height;

	count = 0;
	visible = 0;
	i = 0;
	while (i < N)
	{
		if (reverse)
			height = puzzle[row][N - 1 - i];
		else
			height = puzzle[row][i];
		if (height > visible)
		{
			count++;
			visible = height;
		}
		i++;
	}
	return count;
}

int count_visible_column(int puzzle[N][N], int col, int reverse)
{
	int count;
	int max_seen;
	int i;
	int height;

	count = 0;
	max_seen = 0;
	i = 0;
	while (i < N)
	{
		height = reverse ? puzzle[N - 1 - i][col] : puzzle[i][col];
		if (height > max_seen)
		{
			count++;
			max_seen = height;
		}
		i++;
	}
	return count;
}

// Tsekataan rivit ja sarakkeet. Nyt tsekataan ekaa rivia,
// 1 2 3 4. int X kuvaa rivia tai saraketta.

// Lahetetaan kaikki yksitellen ja tarkistetaan molemmista paista.
// Rivit tarkistetaan cluesin taulukoista 1 ( vasen reuna ) ja
// 3 (oikea reuna). Sarakkeet tarkistetaan 0 ja 2.
// Count_visible funktio laskee maaran, miten paljon skyscrapereita
// nakyy. Jos luku ei vastaa cluesissa maaritettya arvoa, palautetaan
// 0, vaara vastaus.

int is_valid_state(int puzzle[N][N], int clues[4][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (count_visible_row(puzzle, i, 0) != clues[3][i]
			|| count_visible_row(puzzle, i, 1) != clues[1][i])
			return (0);
		if (count_visible_column(puzzle, i, 0) != clues[0][i]
			|| count_visible_column(puzzle, i, 1) != clues[2][i])
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

// If we have finished the whole puzlle (if row == N),
// check if the puzzle checks out all the clues.
// If we have finished one row (if col == N), move to the
// next row with the solve -function.

// The while loop tries all the possible numbers (1 to N) in
// each cell of the row. If a number is valid in a position,
// it returns true. If not, it goes back to 0 and tries the
// next number.

// -> Mainista tultaessa, alotetaan kattomaan 0,0.
// -> Is_validiin lahetetaan puzzle, rivi 0, sarake 0, nro 1.
// -> Is_validista tuli true numerolle 1. Siirrytaan seuraavaan..

// Sitten kun koko rivi valmis (if col == N), puzzle ja cluesit pistetaan
// eteenpain uuteen solve -funktioon joka rupeaa kattomaan
// seuraavaa rivia.

// Vipa rivi eli nro 3 (0-3) jalkeen viela kerran kutsutaan
// rekursiivisesti funktiota solve, jolloin mennaan if row == N osaan,
// joka tarkistaa kaikki rivit ja sarakkeet.

int	solve(int puzzle[N][N], int clues [4][N], int row, int col)
{
	int	nbr;

	if (row == N)
		return is_valid_state(puzzle, clues);
	if (col == N)
		return solve(puzzle, clues, row + 1, 0);
	nbr = 1;
	while (nbr <= N)
	{
		if (is_valid(puzzle, row, col, nbr))
		{
			puzzle[row][col] = nbr;
			if (solve(puzzle, clues, row, col + 1))
				return (1);
		}
		puzzle[row][col] = 0;
		nbr++;
	}
	return (0);
}

int	main(void)
{
	int puzzle[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };
	//Clues 0 = top, 1 = right, 3 = bottom, 4 = left
	int clues[4][N] = { { 3, 4, 1, 2 },
						{ 2, 1, 4, 3 },
						{ 2, 1, 2, 2 },
						{ 2, 2, 1, 2 } };

	if (solve(puzzle, clues, 0, 0))
	{
		print_grid(puzzle);
		return (0);
	}
	else
	{
		printf("No solution available.\n");
		return (1);
	}
	return (0);
}

