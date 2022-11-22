/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:03:08 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/22 18:07:05 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_counter(t_data *d)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(d->map, O_RDONLY);
	if (fd < 1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	column_counter(t_data *d)
{
	int		i;
	int		fd;
	char	*map;

	i = 0;
	fd = open(d->map, O_RDONLY);
	if (fd < 1)
		return (0);
	map = get_next_line(fd);
	while (map[i])
		i++;
	close(fd);
	free(map);
	return (i);
}

void	player_xy(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->matrix[y])
	{
		while (d->matrix[y][x])
		{
			if (d->matrix[y][x] == 'P')
			{
				d->y_pmat = y;
				d->x_pmat = x;
				d->y_p = y * 64;
				d->x_p = x * 64;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	animation(t_data *d, int x, int y)
{
	if (d->time <= 3)
		animation1(d, x, y);
	if (d->time <= 7)
		animation2(d, x, y);
	if (d->time <= 11)
		animation3(d, x, y);
	if (d->time <= 13)
		animation4(d, x, y);
}

void	check_characters(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (d->matrix[y])
	{
		x = 0;
		while (d->matrix[y][x])
		{
			if (d->matrix[y][x] != '1' && d->matrix[y][x] != '0'
				&& d->matrix[y][x] != 'P' && d->matrix[y][x] != 'E'
				&& d->matrix[y][x] != 'C' && d->matrix[y][x] != 'N')
			{
				write(1, "ERROR: WRONG CHARACTERS IN MAP\n", 31);
				ft_close(d);
			}
			x++;
		}
		y++;
	}
}
