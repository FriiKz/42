/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:22:53 by aliburdi          #+#    #+#             */
/*   Updated: 2022/11/22 17:17:18 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = ft_strlen(s1) - 4;
	while ((s2[c] == s1[i]) && (s1[i] != '\0'))
	{
		c++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[c]);
}
