/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:00:38 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/27 15:20:09 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == '\0' && src == '\0')
		return (0);
	if (dest > src)
	{
		while (n-- > 0)
		{
			*(unsigned char *)&dest[n] = *(unsigned char *)&src[n];
		}
	}
	else
	{
		while (n-- > 0)
		{
			*(unsigned char *)&dest[i] = *(unsigned char *)&src[i];
			i++;
		}
	}
	return (dest);
}
