/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:57:54 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/05 16:34:56 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		print_type(const char type, va_list parameter)
{
	if (type == 'c')
		return (ft_putchar(parameter));
	else if (type == 's')
		return (ft_putstr(parameter));
	else if (type == 'p')
		return ();
	else if (type == 'd')
		return (ft_putnbr(parameter));
	else if (type == 'i')
		return (ft_putnbr(parameter));
	else if (type == 'x' || type == 'X')
		return ();
	else if (type == '%')
		return (ft_putchar ('%'));
	return (1);
}

int		ft_printf(const char *, ...)
{
	va_list		arg;
	int			
}