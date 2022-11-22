/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:00:37 by lbusi             #+#    #+#             */
/*   Updated: 2022/10/31 13:04:09 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_c(t_data *d)
{
	int		fd;
	int		i;

	i = d->y_max;
	d->y = 0;
	fd = open(d->map, O_RDONLY);
	if (fd == -1)
		exit(0);
	d->matrix = (char **) malloc (sizeof(char *) * (i) + 1);
	if (!d->matrix)
		return ;
	while (i != 0)
	{
		d->matrix[d->y] = get_next_line(fd);
		d->y++;
		i--;
	}
	close(fd);
	d->matrix[d->y] = NULL;
}

void	free_matrix(t_data *d)
{
	int	i;

	i = 0;
	while (d->matrix[i])
	{
		free(d->matrix[i]);
		i++;
	}
}
