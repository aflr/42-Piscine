/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:27:32 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/26 06:00:37 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	length(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

char	*copy_str(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

long	total_length(int size, char **strs, char *sep)
{
	int		i;
	long	sep_len;
	long	total;

	sep_len = length(sep);
	total = sep_len * (size - 1);
	i = -1;
	while (++i < size)
		total += length(strs[i]);
	return (total + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*str_aux;
	int		i;
	long	total_len;

	if (!size)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	total_len = total_length(size, strs, sep);
	str = (char *)malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);
	i = 0;
	str_aux = str;
	while (i < size)
	{
		str_aux = copy_str(str_aux, strs[i]);
		if (i++ != size - 1)
			str_aux = copy_str(str_aux, sep);
	}
	str[total_len - 1] = '\0';
	return (str);
}
