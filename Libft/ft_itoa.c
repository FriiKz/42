/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:10:31 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/25 16:47:56 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_len(int n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int		num;
	char			*dst;
	size_t			cifre;

	num = n;
	cifre = num_len(n);
	if (n < 0)
	{
		num *= -1;
		cifre++;
	}
	dst = (char *)malloc(sizeof(char) * (cifre + 1));
	if (!dst)
		return (NULL);
	dst[cifre] = 0;
	while (cifre)
	{
		cifre--;
		dst[cifre] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
