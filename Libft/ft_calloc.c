/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:43:24 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/22 11:29:41 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	int		i;

	i = nitems * size;
	ptr = malloc(i);
	if (!ptr)
		return (0);
	ft_bzero(ptr, i);
	return (ptr);
}
