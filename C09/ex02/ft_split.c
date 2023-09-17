/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:48:08 by aflorido          #+#    #+#             */
/*   Updated: 2023/07/25 03:13:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	index_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (!in_word && index_in_string(str[i], charset) == -1)
		{
			in_word = 1;
			++count;
		}
		else if (in_word && index_in_string(str[i], charset) != -1)
			in_word = 0;
		++i;
	}
	return (count);
}

char	*next_non_sep_len(char *str, char *sep, int *len)
{
	while (*str && index_in_string(*str, sep) != -1)
		++str;
	*len = 0;
	while (str[*len] && index_in_string(str[*len], sep) == -1)
		*len = *len + 1;
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**res;
	int		len;
	int		i;
	int		j;

	word_count = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	while (i < word_count)
	{
		str = next_non_sep_len(str, charset, &len);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (j < len)
			res[i][j++] = *str++;
		res[i][j] = '\0';
		++i;
	}
	res[word_count] = NULL;
	return (res);
}
