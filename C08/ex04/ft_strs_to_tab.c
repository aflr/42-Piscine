/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:49:33 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/25 04:05:39 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (str_len(src) + 1));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}

//(type){initializer-list} is a compound literal
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;

	res = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		res[i].size = str_len(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
	}
	res[i] = (struct s_stock_str){.size = 0, .str = 0, .copy = 0};
	return (res);
}
