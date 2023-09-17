/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 04:50:43 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/20 05:43:52 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	should_check(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	x = (int)(nb & 0xF);
	return (x == 0 || x == 1 || x == 4 || x == 9);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (!should_check(nb))
		return (0);
	i = -1;
	while (++i <= 46340)
	{
		if (i * i >= nb)
			return (i * (i * i == nb));
	}
	return (0);
}
