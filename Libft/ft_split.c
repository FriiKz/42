/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:48:44 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/25 16:27:43 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char const *s, char c)
{
	size_t	word_update;

	word_update = 0;
	while (*s)
	{
		if (*s != c)
		{
			++word_update;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (word_update);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			dst[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	dst[i] = 0;
	return (dst);
}
