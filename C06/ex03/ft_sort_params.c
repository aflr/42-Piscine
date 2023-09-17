/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:45:27 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/18 23:01:41 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_v(int i, int c, char **v)
{
	int	j;

	while (++i < c)
	{
		j = -1;
		while (v[i][++j])
			write(1, v[i] + j, 1);
		write(1, "\n", 1);
	}
}

int	main(int c, char **v)
{
	int		i;
	int		is_sorted;
	char	*aux;

	is_sorted = 0;
	while (!is_sorted)
	{
		i = 1;
		is_sorted = 1;
		while (++i < c)
		{
			if (compare(v[i - 1], v[i]) > 0)
			{
				aux = v[i];
				v[i] = v[i - 1];
				v[i - 1] = aux;
				is_sorted = 0;
			}
		}
	}
	print_v(0, c, v);
}
