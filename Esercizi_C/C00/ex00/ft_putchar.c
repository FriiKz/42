/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:38:34 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/03 18:26:51 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char L)
{
	write(1, &L, 1);
}
