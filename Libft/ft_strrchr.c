/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:28:52 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/27 15:21:46 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				size_max;
	unsigned char	ucc;

	ucc = c;
	size_max = ft_strlen((char *)str) - 1;
	if (str[size_max + 1] == ucc)
		return ((char *)&str[size_max + 1]);
	while (size_max >= 0)
	{
		if (ucc == (str[size_max]))
			return ((char *)&str[size_max]);
		else
			size_max--;
	}
	return (NULL);
}
