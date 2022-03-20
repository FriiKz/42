/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:23 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:27:37 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == str[i])
		return ((char *)&str[i]);
	while (str[i])
	{
		if (c == str[i])
			return ((char *)&str[i]);
		else
		i++;
	}
	return (NULL);
}
