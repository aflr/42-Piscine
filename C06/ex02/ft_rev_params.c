/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:40:00 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/18 20:44:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;

	while (--argc > 0)
	{
		j = 0;
		while (argv[argc][j])
			write(1, argv[argc] + j++, 1);
		write(1, "\n", 1);
	}
}
