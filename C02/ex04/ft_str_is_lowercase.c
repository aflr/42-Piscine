/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:03:30 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/10 16:04:47 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	lower;

	lower = 1;
	while (lower && *str)
	{
		lower = (*str >= 'a' && *str <= 'z');
		str++;
	}
	return (lower);
}
