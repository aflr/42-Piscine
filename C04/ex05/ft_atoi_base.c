/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:40:25 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/19 15:24:03 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	index_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		++i;
	}
	return (-1);
}

int	atoi_base(char *str, char *base, int base_len)
{
	long	res;
	int		sign_parity;
	int		i;

	res = 0;
	sign_parity = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			++sign_parity;
		++i;
	}
	while (index_in_string(str[i], base) >= 0)
	{
		res *= base_len;
		res += index_in_string(str[i++], base);
	}
	if (sign_parity % 2)
		return ((int)-res);
	return ((int)res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;

	base_length = str_len_checking_symbols(base);
	if (base_length < 2 || repeat_chars(base))
		return (0);
	return (atoi_base(str, base, base_length));
}
