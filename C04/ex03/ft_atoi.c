/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:10:50 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/13 19:29:48 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	long	res;
	int		sign_parity;
	int		i;

	res = 0;
	sign_parity = 0;
	i = -1;
	while ((str[++i] >= 9 && str[i] <= 13) || str[i] == ' ')
		;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			++sign_parity;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i++] - '0');
	}
	if (sign_parity % 2)
		return ((int)-res);
	return ((int)res);
}
