/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_printf_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:19:14 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/13 19:39:32 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	temp;

	temp = 0;
	if (nb == -2147483648)
	{
		temp += ft_putnbr(nb / 10);
		temp += ft_putchar('8');
	}
	else if (nb < 0)
	{
		temp += ft_putchar('-');
		temp += ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			temp += ft_putnbr(nb / 10);
		}
		temp += ft_putchar(48 + nb % 10);
	}
	return (temp);
}

int	ft_put_uint_nbr(unsigned int nb)
{
	if (nb == 4294967295)
	{
		ft_putnbr(nb / 10);
		ft_putchar('5');
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
	if (nb < 0)
		return (long_len(4294967295 - nb + 1, 10));
	return (long_len(nb, 10));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
