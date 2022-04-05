/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_printf_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:45:20 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/05 16:31:57 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_len(uintptr_t num)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_hex(uintptr_t num, const char type)
{
	 if (num >= 16)
	 {
		 ft_hex(num / 16, type);
		 ft_hex(num % 16, type);
	 }
	 else
	 {
		if (num <= 9)
				ft_putchar(num + '0');
		else
		{
			if (type == 'x')
				ft_putchar((num - 10 + 'a'));
			if (type == 'X')
				ft_putchar(num - 10 + 'A');
		}
	 }
}

int		ft_hex_print(unsigned long long num, const char type)
{
	if (num == 0)
		return (write(1, '0', 1));
	else
		ft_put_hex(num, type);
	return (ft_hex_len(num));
}
