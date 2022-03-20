/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:48:12 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/18 16:21:41 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_size;

	dest_size = ft_strlen(dst) + ft_strlen(src);
	if (size < 1)
		return (i);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	i = 0;
	while (src[i] && i < size - (dest_size - ft_strlen(src)) - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dest_size);
}
