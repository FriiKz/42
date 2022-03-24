/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:58:46 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/07 11:58:11 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (a++ < 98)
	{
		b = a;
		while (b++ < 99)
		{
			print_num((a / 10) + '0');
			print_num((a % 10) + '0');
			print_num(' ');
			print_num((b / 10) + '0');
			print_num((b % 10) + '0');
			if (a < 98)
			{
				print_num(',');
				print_num(' ');
			}
		}
	}
}
