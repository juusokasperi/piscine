/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:12:56 by jrinta-           #+#    #+#             */
/*   Updated: 2024/07/07 11:22:25 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

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

void	initialize_puzzle(int puzzle[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			puzzle[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	initialize_clues(int clues[4][N], int argc, char **argv)
{
	int	i;
	int	j;
	int	argv_iterator;
	int	clue;

	argv_iterator = 1;
	if (argc != 17)
		return (0);
	i = 1;
	while (i <= N)
	{
		j = 0;
		while (j < N)
		{
			clue = ft_atoi(argv[argv_iterator]);
			if (clue < 1 || clue > N)
				return (0);
			clues[i - 1][j] = clue;
			j++;
			argv_iterator++;
		}
		i++;
	}
	return (1);
}

int	initialize(int puzzle[N][N], int clues[4][N], int argc, char **argv)
{
	initialize_puzzle(puzzle);
	if (initialize_clues(clues, argc, argv))
		return (1);
	else
		return (0);
}
