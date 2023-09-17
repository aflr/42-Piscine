/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:43:21 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/10 15:54:37 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	alpha;

	alpha = 1;
	while (alpha && *str)
	{
		alpha = ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'));
		str++;
	}
	return (alpha);
}
