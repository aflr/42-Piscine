/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:35:29 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/22 19:11:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	length(char *str, unsigned int z)
{
	while (str[z])
		++z;
	return (z);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_size;
	unsigned int	i;

	dst_size = length(dest, 0);
	i = 0;
	while (src[i] && i + dst_size + 1 < size)
	{
		dest[dst_size + i] = src[i];
		++i;
	}
	if (size >= dst_size)
		dest[dst_size + i] = '\0';
	if (size >= dst_size)
		return (dst_size + length(src, 0));
	return (size + length(src, 0));
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	des1[50] = "1234";
	char	des2[50] = "1234";
	char	*src = "abcdef";
	int		n;

	n = 2147483647;
	printf("%u->%s.\n", ft_strlcat(des1, src, n), des1);
	printf("%lu->%s.\n", strlcat(des2, src, n), des2);
}
*/
