/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:41:29 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/27 15:20:53 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
	{
		if (*(unsigned char *)&s[i] == *(unsigned char *)&c)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}
