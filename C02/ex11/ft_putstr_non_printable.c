/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:36 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/12 02:38:34 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(int c)
{
	const char	*xdigits = "0123456789abcdef";

	write(1, "\\", 1);
	write(1, xdigits + (unsigned char)c / 16, 1);
	write(1, xdigits + (unsigned char)c % 16, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] == 127)
			write_hex(str[i]);
		else
			write(1, str + i, 1);
	}
}
