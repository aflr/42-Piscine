/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:18:41 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/20 16:38:02 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(long n)
{
	long	i;

	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return (0);
	if (n <= 3)
		return (1);
	i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	if (nb % 2 == 0)
		++nb;
	while (!is_prime((long)nb))
		nb += 2;
	return (nb);
}
