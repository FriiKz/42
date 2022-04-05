/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolaiac <ccolaiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:23:59 by ccolaiac          #+#    #+#             */
/*   Updated: 2022/03/27 16:24:21 by ccolaiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t	ft_count_a(const char *s, char c)
{
	int	i;
	int	find_word;
	int	array;

	i = 0;
	array = 0;
	if (!s[i])
		return (0);
	if (s[i])
		i++;
	while (s[i])
	{
		find_word = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			find_word = 1;
		}
		if (find_word == 1)
			array++;
	}
	return (array);
}

void	ft_word_len(char const *s, char c, size_t *i, size_t *start)
{
	while (s[*i] == c)
			(*i)++;
		*start = *i;
	while (s[*i] != c && s[*i])
			(*i)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	array;
	size_t	start;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	array = ft_count_a(s, c);
	str = malloc((array + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (s[i] && j < array)
	{
		ft_word_len(s, c, &i, &start);
		str[j] = ft_substr(s, start, i - start);
		j++;
	}
	str[j] = 0;
	return (str);
}
