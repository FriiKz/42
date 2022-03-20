/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:28:52 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:29:19 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	size_max;

	size_max = ft_strlen((char *)str);
	while (str[size_max - 1])
	{
		if (c == (str[size_max]))
			return ((char *)&str[size_max]);
		else
		size_max--;
	}
	return (NULL);
}
