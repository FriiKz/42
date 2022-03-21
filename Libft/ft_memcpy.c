/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:35:41 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/21 16:41:44 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (*(unsigned char *)&dest[i] && (n-- > 0) && *(unsigned char *)&src[i])
	{
		*(unsigned char *)&dest[i] = *(unsigned char *)&src[i];
		i++;
	}
	return (dest);
}
