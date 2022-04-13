/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:37:13 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/12 18:01:23 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_len(uintptr_t num)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

void		ft_ptr_conv(uintptr_t num)
{
	if (num >= 16)
	{
		ft_ptr_conv(num / 16);
		ft_ptr_conv (num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int		ft_ptr_print(uintptr_t num)
{
	int		len;

	len = 0;
	write(1, "0x", 2);
	if (num == 0)
		return (write(1, "0", 1) + 2);
	else
		ft_ptr_conv(num);
	return (ft_ptr_len(num) + 2);
}