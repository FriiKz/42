/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:31:12 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/22 13:04:09 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	count;
	int	number;
	int	operator;

	count = 0;
	number = 0;
	operator = 1;
	while (str[count] == '\t' || str[count] == '\n' || str[count] == '\v'
		|| str[count] == '\f' || str[count] == '\r' || str[count] == ' ')
		count++;
	while (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			operator *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		number *= 10;
		number += str[count] - '0';
		count++;
	}
	return (number * operator);
}
