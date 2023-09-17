/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:06:54 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/10 16:09:43 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	printable;

	printable = 1;
	while (printable && *str)
	{
		printable = (*str >= 32 && *str <= 126);
		str++;
	}
	return (printable);
}
