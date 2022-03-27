/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:35:41 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/27 15:18:47 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == '\0' && src == '\0')
		return (0);
	while (n-- > 0)
	{
		*(unsigned char *)&dest[i] = *(unsigned char *)&src[i];
		i++;
	}
	return (dest);
}
