/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:41:07 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/08 01:21:50 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	is_sorted;

	if (size < 2)
		return ;
	is_sorted = 0;
	while (!is_sorted)
	{
		i = 0;
		is_sorted = 1;
		while (++i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				tab[i] ^= tab[i - 1];
				tab[i - 1] ^= tab[i];
				tab[i] ^= tab[i - 1];
				is_sorted = 0;
			}
		}
	}
}
