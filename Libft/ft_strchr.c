/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:23 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/22 11:42:12 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ucc;

	ucc = c;
	i = 0;
	while (str[i])
	{
		if (ucc == str[i])
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ucc)
		return ((char *)&str[i]);
	return (NULL);
}
