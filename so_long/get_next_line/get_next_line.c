/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:13:39 by aliburdi          #+#    #+#             */
/*   Updated: 2022/10/29 17:47:45 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (0);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (0);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free (save);
	return (s);
}

char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	bytes = 1;
	while (!ft_strrchr(save, '\n') && bytes != 0)
	{	
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free (buffer);
	return (save);
}

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*save[257];

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	save[fd] = ft_read_save(fd, save[fd]);
// 	if (!save[fd])
// 		return (0);
// 	line = ft_get_line(save[fd]);
// 	save[fd] = ft_save(save[fd]);
// 	return (line);
// }
void	helper(char *new_a, int i)
{
	if (new_a[i - 1] == '\n')
		new_a[i - 1] = '\0';
	new_a[i] = '\0';
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n' || !a[i])
			break ;
		i++;
	}
	if (a[0] == '\n' || !a[0])
		return (NULL);
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = -1;
	while (a[++i])
		new_a[i] = a[i];
	helper(new_a, i);
	return (new_a);
}
