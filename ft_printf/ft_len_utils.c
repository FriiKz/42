/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:30:51 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/13 18:54:05 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	len(int nb, int base)
{
	int	i;

	i = 0;
	if (nb <= 0)
		++i;
	while (nb && i++)
		nb = nb / base;
	return (i);
}

int	long_len(long long nb, int base)
{
	int	i;

	i = 0;
	if (nb <= 0)
		++i;
	while (nb && ++i)
		nb = nb / base;
	return (i);
}
