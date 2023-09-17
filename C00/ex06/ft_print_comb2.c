/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:48:19 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/06 14:48:21 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int n)
{
	char	left;
	char	right;

	left = n / 10 + '0';
	right = n % 10 + '0';
	write(1, &left, 1);
	write(1, &right, 1);
}

void	ft_print_comb2(void)
{
	int	ln;
	int	rn;

	ln = -1;
	while (++ln <= 98)
	{
		rn = ln;
		while (++rn <= 99)
		{
			print_number(ln);
			write(1, " ", 1);
			print_number(rn);
			if (ln != 98)
				write(1, ", ", 2);
		}
	}
}
