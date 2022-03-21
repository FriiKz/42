/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:48:12 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/20 18:54:09 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_size;

	i = 0;
	dest_size = ft_strlen(dst) + ft_strlen(src);
	if (size < 1)
		return (i);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (src[i] && i < size - (dest_size - ft_strlen(src)) - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dest_size);
}
