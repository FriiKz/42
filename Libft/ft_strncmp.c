/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:34:59 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:30:36 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i]) && (n > 0) && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
