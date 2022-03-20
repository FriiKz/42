/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:09:37 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 19:54:00 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (((*(unsigned char *)&s1[i] == *(unsigned char *)&s2[i]) && (n > 0) && (*(unsigned char *)&s1[i])))
	{
		i++;
		n--;
	}
	return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
}

#include <stdio.h>

int main()
{
	char c[] = "ciao";
	char d[] = "ciao";
	printf("%d", ft_memcmp(c, d, 4));
}