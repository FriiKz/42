/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:47:55 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/23 18:17:06 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	index;

	index = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (index <= (nb / 2) && index < 46341)
	{
		if (index * index == nb)
		{
			return (index);
		}
		index++;
	}
	return (0);
}
