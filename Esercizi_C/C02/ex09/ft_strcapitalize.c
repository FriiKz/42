/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:02 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/16 14:46:18 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		count;
	char	*temp;

	count = 1;
	temp = str;
	while (*str != '\0')
	{
		if (((count == 1)) && (*str >= 97 && *str <= 122))
		{
			*str -= 32;
			count = 0;
		}
		else if (((*str >= 0) && (*str <= 47))
			|| ((*str >= 58) && (*str <= 64))
			|| ((*str >= 91) && (*str <= 96))
			|| ((*str >= 123) && (*str <= 127)))
			count = 1;
		else if (((*str >= 65) && (*str <= 90))
			&& (count == 0))
			*str += 32;
		else
			count = 0;
		str++;
	}
	return (temp);
}
