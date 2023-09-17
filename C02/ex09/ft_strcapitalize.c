/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:46:10 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/10 18:23:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	to_case(char c, int target_case)
{
	if (target_case && c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	if (!target_case && c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	next_upper;
	int	i;

	next_upper = 1;
	i = -1;
	while (str[++i])
	{
		str[i] = to_case(str[i], next_upper);
		next_upper = !(is_alphanum(str[i]));
	}
	return (str);
}
