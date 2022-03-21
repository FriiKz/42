/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:28:52 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/21 16:00:02 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	size_max;

	size_max = ft_strlen((char *)str) - 1;
	if (str[size_max + 1] == c)
		return ((char *)&str[size_max + 1]);
	while (size_max >= 0)
	{
		if (c == (str[size_max]))
			return ((char *)&str[size_max]);
		else
		size_max--;
	}
	return (NULL);
}
