/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:00:38 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:44:42 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (*(unsigned char *)&dest[i] && (n > 0))
	{
		*(unsigned char *)&dest[i] = *(unsigned char *)&src[i];
		i++;
		n--;
	}
	return (dest);
}
#include <stdio.h>

int main()
{
    char c[] = "ciao";
    char d[] = "bello";
    printf("%s\n", memmove(c, d, 5));
    printf("%s", ft_memmove(c, d, 5));
}
