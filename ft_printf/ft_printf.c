/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:57:54 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/13 19:32:08 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(const char type, va_list parameter)
{
	int	temp;

	temp = 0;
	if (type == 'c')
		temp += (ft_print_char(parameter));
	else if (type == 's')
		temp += (ft_putstr(va_arg(parameter, char *)));
	else if (type == 'p')
		temp += (ft_ptr_print(va_arg(parameter, uintptr_t)));
	else if (type == 'd' || type == 'i')
		temp += (ft_putnbr(va_arg(parameter, int)));
	else if (type == 'u')
		temp += (ft_put_uint_nbr(va_arg(parameter, unsigned int)));
	else if (type == 'x' || type == 'X')
		temp += (ft_hex_print(va_arg(parameter, unsigned int), type));
	else if (type == '%')
		temp += (ft_putchar ('%'));
	return (temp);
}

int	ft_printf(const char *s, ...)
{
	va_list		arg;
	int			i;
	int			temp;

	i = 0;
	temp = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			temp = temp + print_type(s[i], arg);
			i++;
		}
		if (!s[i])
			return (temp);
		if (s[i] != '%')
		{
			temp++;
			ft_putchar(s[i]);
			i++;
		}
	}
	return (temp);
}

// int	main()
// {
// 	int	i;

// 	i = 2147483647;
// 	//printf("\n%d", printf(" %i", 12));
// 	printf("\n%d", ft_printf("%i", 12));
// }
//gcc ft_printf.c ft_basic_printf_utils.c ft_char_utils.c 
//ft_hex_utils.c ft_ptr_utils.c ft_len_utils.c