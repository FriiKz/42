/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:48:28 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:33:49 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (j + i) < n)
		{
			if (needle[i + 1] == '\0')
				return ((char *)&haystack[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}
