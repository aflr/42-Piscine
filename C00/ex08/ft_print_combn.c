/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:48:50 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/13 02:07:23 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combn_recursive(int n, int curr_pos, int curr_val, int *buffer);

void	ft_print_combn(int n)
{
	int	b[9];

	print_combn_recursive(n, 0, 0, b);
}

void	print_combn_recursive(int n, int curr_pos, int curr_val, int *buffer)
{
	const char	*elem = "0123456789";
	int			i;

	if (curr_pos == n)
	{
		i = 0;
		while (i < n)
			write(1, elem + (buffer[i++]), 1);
		if (buffer[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (curr_val <= 9)
	{
		buffer[curr_pos] = curr_val;
		print_combn_recursive(n, curr_pos + 1, ++curr_val, buffer);
	}
}
