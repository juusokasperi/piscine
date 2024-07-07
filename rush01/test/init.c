/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:12:56 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 15:02:13 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	atoi;

	s = 1;
	i = 0;
	atoi = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	return (s * atoi);
}

void	initialize_puzzle(int puzzle[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			puzzle[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	initialize_clues(int clues[4][4], int argc, char **argv)
{
	int	i;
	int	j;
	int	argv_iterator;
	int	clue;

	argv_iterator = 1;
	if (argc != 17)
		return (0);
	i = 1;
	while (i <= 4)
	{
		j = 0;
		while (j < 4)
		{
			clue = ft_atoi(argv[argv_iterator]);
			if (clue < 1 || clue > 4)
				return (0);
			clues[i - 1][j] = clue;
			j++;
			argv_iterator++;
		}
		i++;
	}
	return (1);
}

int	initialize(int puzzle[4][4], int clues[4][4], int argc, char **argv)
{
	initialize_puzzle(puzzle);
	if (initialize_clues(clues, argc, argv))
		return (1);
	else
		return (0);
}
