/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:41:44 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/12 02:45:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(void *addr)
{
	const char			*xdigits = "0123456789abcdef";
	char				result[16];
	long unsigned int	int_address;
	int					i;

	i = 0;
	while (i < 16)
		result[i++] = '0';
	int_address = (long unsigned int) addr;
	i = 0;
	while (int_address > 0)
	{
		result[15 - i++] = xdigits[int_address % 16];
		int_address /= 16;
	}
	write(1, result, 16);
	write(1, ": ", 2);
}

void	write_char_hex(char *c)
{
	const char	*xdigits = "0123456789abcdef";

	write(1, xdigits + (unsigned char)(*c) / 16, 1);
	write(1, xdigits + (unsigned char)(*c) % 16, 1);
}

void	write_char_or_dot(char *c)
{
	if (*c >= 32 && *c <= 126)
		write(1, c, 1);
	else
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	counter;
	unsigned int	aux;

	i = 0;
	counter = 0;
	while (i < size && ++counter)
	{
		print_address(addr + i);
		aux = i;
		while ((i + counter) % 17)
		{
			if (i < size)
				write_char_hex((char *)(addr + i));
			else
				write(1, "  ", 2);
			if (!(++i % 2))
				write(1, " ", 1);
		}
		i = aux;
		while ((i + counter) % 17 && i < size)
			write_char_or_dot((char *)(addr + i++));
		write(1, "\n", 1);
	}
	return (addr);
}
