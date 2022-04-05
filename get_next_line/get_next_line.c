/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolaiac <ccolaiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:41:13 by ccolaiac          #+#    #+#             */
/*   Updated: 2022/03/28 19:58:58 by ccolaiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	ft_copy_line(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i] != '\n' && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[i] = '\n';
	dst[i + 1] = '\0';
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen(s) <= len)
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < (unsigned int) ft_strlen(s))
	{
		while (i < len && s[start] != '\0')
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*next_line;
	int			offset;
	int			returnread;
	int			n;

	n = 0;
	if (fd < 0)
		return (NULL);
	next_line = (char *)malloc(ft_strlen());
	if (!saved[n] || !(*saved[n]))
	{
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (buf[0] == '\0')
		{
			free(saved[fd]);
			return (NULL);
		}
		saved[n] = ft_strdup(buf);
	}
	returnread = 1;
	while (!ft_strchr(saved[n], '\n') && returnread > 0)
	{
		returnread = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		saved[n] = ft_strjoin(saved[n], buf);
	}
	offset = ft_copy_line(saved[n], next_line);
	saved[n] = ft_substr(saved[n], offset + 1, ft_strlen(saved[n]));
	return (next_line);
}

int	main(void)
{
	int	i;

	i = open("prova", O_RDONLY);
	printf ("%s", get_next_line(i));
	printf ("%s", get_next_line(i));
	printf ("%s", get_next_line(i));
	printf ("%s", get_next_line(i));
	close(i);
}
