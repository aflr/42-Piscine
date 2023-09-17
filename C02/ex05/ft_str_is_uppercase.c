/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:05:39 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/11 12:27:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	upper;

	upper = 1;
	while (upper && *str)
	{
		upper = (*str >= 'A' && *str <= 'Z');
		str++;
	}
	return (upper);
}
