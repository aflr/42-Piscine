/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:44:40 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/20 06:15:55 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Binary search for integer square root, sometimes more
int	approx_isqrt(int y)
{
	long int	left;
	long int	middle;
	long int	right;

	left = 0;
	right = y;
	while (right - left > 4)
	{
		middle = (left + right) / 2;
		if (middle * middle <= y)
			left = middle;
		else
			right = middle;
	}
	return ((int)right);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	i = 2;
	while (i <= approx_isqrt(nb))
	{
		if (nb % i++ == 0)
			return (0);
	}
	return (1);
}
