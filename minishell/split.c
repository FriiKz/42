/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:00 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/20 11:51:39 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

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
