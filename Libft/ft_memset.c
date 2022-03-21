/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:46:29 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/20 18:59:24 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		*(unsigned char *)&str[j] = (unsigned char)c;
		j++;
		i++;
	}
	return (str);
}