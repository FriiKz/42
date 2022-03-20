/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:51 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/07 17:47:47 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	int	i;

	i = 0;
	if (dstsize < 1)
	{
		return (i);
	}
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
