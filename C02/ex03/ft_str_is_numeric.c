/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:55:57 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/10 15:57:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	numeric;

	numeric = 1;
	while (numeric && *str)
	{
		numeric = (*str >= '0' && *str <= '9');
		str++;
	}
	return (numeric);
}
