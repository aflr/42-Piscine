/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:39:48 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/19 15:23:37 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len_checking_symbols(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str <= 32 || *str == '+' || *str == '-' || *str == 127)
			return (0);
		++len;
		++str;
	}
	return (len);
}

int	repeat_chars(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = i;
		while (str[++j])
		{
			if (str[i] == str[j])
				return (1);
		}
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_length;
	long int	lnbr;

	base_length = str_len_checking_symbols(base);
	if (base_length < 2)
		return ;
	if (repeat_chars(base))
		return ;
	lnbr = nbr;
	if (lnbr == 0)
		write(1, base, 1);
	if (lnbr < 0 && write(1, "-", 1))
		lnbr = -lnbr;
	if (lnbr > 0)
	{
		if (lnbr / base_length)
			ft_putnbr_base(lnbr / base_length, base);
		write(1, base + (lnbr % base_length), 1);
	}
}
