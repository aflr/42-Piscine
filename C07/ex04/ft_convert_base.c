/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:15:13 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/24 01:45:11 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	index_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char	*itoa_base(int num, char *base_to, int base_len)
{
	char	*res;
	long	num_copy;
	int		negative;
	int		i;

	res = (char *)malloc(sizeof(char) * 34);
	res[33] = '\0';
	num_copy = num;
	i = 32;
	negative = num < 0;
	if (negative)
		num_copy = -num_copy;
	if (num == 0)
		res[i--] = base_to[0];
	while (num_copy > 0)
	{
		res[i--] = base_to[num_copy % base_len];
		num_copy /= base_len;
	}
	if (negative)
		res[i--] = '-';
	return (res + i + 1);
}

int	atoi_base(char *str, char *base_from, int base_len)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		++i;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	res = 0;
	while (str[i] && index_in_string(str[i], base_from) >= 0)
	{
		res *= base_len;
		res += index_in_string(str[i++], base_from);
	}
	return ((int)(res * sign));
}

int	valid_base_len(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (-1);
		}
		if (base[i] <= 32 || base[i] == 127
			|| base[i] == '+' || base[i] == '-')
			return (-1);
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_from_len;
	int		base_to_len;

	base_from_len = valid_base_len(base_from);
	base_to_len = valid_base_len(base_to);
	if (base_from_len < 2 || base_to_len < 2)
		return (NULL);
	num = atoi_base(nbr, base_from, base_from_len);
	return (itoa_base(num, base_to, base_to_len));
}
