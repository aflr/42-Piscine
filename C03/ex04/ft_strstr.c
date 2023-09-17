/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:20:36 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/19 03:34:11 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!*to_find)
		return (str);
	i = 0;
	while (*str)
	{
		j = -1;
		while (to_find[++j] && str[j] == to_find[j])
			;
		if (!to_find[j])
			return (str);
		++str;
	}
	return (0);
}
