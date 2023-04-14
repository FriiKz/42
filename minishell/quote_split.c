/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:49:00 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/14 18:50:04 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_counter(char *s, t_data *t)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			t->quotes++;
		i++;
	}
	//printf("%d\n", t->quotes);
}

size_t	word_count(char const *s, char c, t_data *t)
{
	size_t	word_update;
	int		i;

	i = 0;
	word_update = 0;
	while (s[i])
	{
		if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"' && s[i])
				i++;
			i++;
			word_update++;
			t->quotes -= 2;
		}
		else if (s[i] != c)
		{
			++word_update;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	//printf("%zu\n", word_update);
	return (word_update);
}

char	**ft_split(char const *s, char c, t_data *t)
{
	int		i;
	int		j;
	char	**dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = malloc((word_count(s, c, t) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (*s)
	{
		if (*s == '\"')
		{
			j = 0;
			s++;
			while (*s != '\"' && *s && ++j)
				s++;
			dst[i++] = ft_substr(s - j, 0, j);
			//printf("%d\n", j);
			s++;
		}
		else if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				s++;
			dst[i++] = ft_substr(s - j, 0, j);
			//printf("%d\n", j);
		}
		else
			++s;
	}
	dst[i] = 0;
	return (dst);
}

// void	split_component(t_data *t)
// {
	
// }