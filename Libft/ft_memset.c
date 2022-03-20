/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:46:29 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:14:06 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;
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
