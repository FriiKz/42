/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:57:54 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/13 18:33:57 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(const char type, va_list parameter)
{
	if (type == 'c')
		return (ft_print_char(parameter));
	else if (type == 's')
		return (ft_putstr(va_arg(parameter, char *)));
	else if (type == 'p')
		return (ft_ptr_print(va_arg(parameter, uintptr_t)));
	else if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(parameter, int)));
	else if (type == 'u')
		return (ft_put_uint_nbr(va_arg(parameter, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_hex_print(va_arg(parameter, unsigned int), type));
	else if (type == '%')
		return (ft_putchar ('%'));
	return (1);
}

int	ft_printf(const char *a, ...)
{
	va_list		arg;
	int			i;
	int			temp;

	i = 0;
	temp = 0;
	va_start(arg, a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			i++;
			temp = temp + print_type(a[i], arg);
			i++;
		}
		if (!a[i])
			return (temp);
		if (a[i] != '%')
		{
			temp++;
			ft_putchar(a[i]);
			i++;
		}
	}
	return (temp);
}

// int	main()
// {
// 	unsigned int	i = 50;

// 	printf("%%\n", i);
// 	ft_printf("%%", i);
// }
//gcc ft_printf.c ft_basic_printf_utils.c ft_char_utils.c 
//ft_hex_utils.c ft_ptr_utils.c