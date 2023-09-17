/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 04:12:17 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/25 04:25:24 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_str_nl(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

// We can assume sizes to be non negative
void	put_nbr(int nbr)
{
	const char	*digits = "0123456789";

	if (nbr > 9)
		put_nbr(nbr / 10);
	write(1, digits + (nbr % 10), 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		put_str_nl((*par).str);
		put_nbr((*par).size);
		write(1, "\n", 1);
		put_str_nl((*par).copy);
		++par;
	}
}
