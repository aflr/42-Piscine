/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:22:02 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/23 00:34:15 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BOARD_SIZE 10

int	abs_value(int num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

int	is_safe(int board[BOARD_SIZE], int row, int col)
{
	int	i;

	i = -1;
	while (++i < row)
	{
		if (board[i] == col || abs_value(board[i] - col) == abs_value(i - row))
			return (0);
	}
	return (1);
}

int	ft_ten_queens_puzzle_rec(int board[BOARD_SIZE], int row)
{
	int		i;
	int		count_solutions;
	int		col;
	char	solution[BOARD_SIZE + 1];

	if (row == BOARD_SIZE)
	{
		i = -1;
		while (++i < BOARD_SIZE)
			solution[i] = board[i] + '0';
		solution[BOARD_SIZE] = '\n';
		write(1, solution, BOARD_SIZE + 1);
		return (1);
	}
	count_solutions = 0;
	col = -1;
	while (++col < BOARD_SIZE)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			count_solutions += ft_ten_queens_puzzle_rec(board, row + 1);
		}
	}
	return (count_solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[BOARD_SIZE];
	int	i;

	i = -1;
	while (++i < BOARD_SIZE)
		board[i] = 0;
	return (ft_ten_queens_puzzle_rec(board, 0));
}
