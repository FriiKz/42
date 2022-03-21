/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:43:53 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/21 15:33:03 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			*(unsigned char *)&s[i] = 0;
			i++;
		}
		n--;
	}
}
// #include <stdio.h>

// int main()
// {
// 	char c[] = "ciao";
// 	printf("%s", ft_bzero(c, 4));
// 	printf("%s", bzero(c, 4));
// }