/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:27:30 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/21 15:01:02 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	total_size;

	dest_size = 0;
	while (*dest != '\0')
	{
		dest++;
		dest_size++;
	}
	total_size = dest_size;
	while (*src != '\0')
	{
		if ((int)(size) - (int)(total_size) > 1)
		{
			*dest = *src;
			dest++;
		}
		total_size++;
		src++;
	}
	if (size && size >= dest_size)
		*dest = '\0';
	return (total_size);
}
