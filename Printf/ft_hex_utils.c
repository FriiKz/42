/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:45:20 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/05 18:30:32 by lbusi            ###   ########.fr       */
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

void	ft_hex(uintptr_t num, const char format)
{
	 if (num >= 16)
	 {
		 ft_hex(num / 16, format);
		 ft_hex(num % 16, format);
	 }
	 else
	 {
		if (num <= 9)
				ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	 }
}

int		ft_hex_print(unsigned long long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, format);
	return (ft_hex_len(num));
}
