/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:12:16 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/22 01:16:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	*oa;

	if (min >= max)
		return (NULL);
	a = (int *)malloc(sizeof(int) * (max - min));
	if (a == NULL)
		return (NULL);
	oa = a;
	while (min < max)
		*a++ = min++;
	return (oa);
}
