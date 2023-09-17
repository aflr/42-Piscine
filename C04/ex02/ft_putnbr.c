/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:06:16 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/12 03:09:42 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	lnb;
	char	arr[10];
	int		i;

	lnb = nb;
	if (!lnb)
		write(1, "0", 1);
	if (lnb < 0 && write(1, "-", 1))
		lnb = -lnb;
	i = 0;
	while (lnb)
	{
		arr[i++] = lnb % 10 + '0';
		lnb /= 10;
	}
	while (--i >= 0)
		write(1, arr + i, 1);
}
