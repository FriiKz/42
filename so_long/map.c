/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:16 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/22 17:38:20 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_data *d)
{
	int		i;

	i = d->y_max;
	d->y = 0;
	while (i != 0)
	{
		d->x = 0;
		while (d->matrix[d->y][d->x])
		{
			map_loader(d->matrix[d->y][d->x], d);
			d->x++;
		}
		d->y++;
		i--;
	}
}

void	map_loader(char map, t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->floor, d->x * 64, d->y * 64);
	if (map == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->tree,
			d->x * 64, d->y * 64);
	if (map == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->kid8,
			d->x * 64, d->y * 64);
	if (map == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->page,
			d->x * 64, d->y * 64);
	if (map == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor,
			d->x * 64, d->y * 64);
	if (map == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->pf, d->x * 64, d->y * 64);
	if (map == 'N')
		mlx_put_image_to_window(d->mlx, d->win, d->n,
			d->x * 64, d->y * 64);
}

void	walls_check_lines(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->matrix[y][x])
	{
		if (d->matrix[y][x] != '1')
		{
			write(1, "ERROR: INVALID MAP!", 19);
			ft_close(d);
		}
		x++;
	}
	x = 0;
	y = d->y_max - 1;
	while (d->matrix[y][x])
	{
		if (d->matrix[y][x] != '1')
		{
			write(1, "ERROR: INVALID MAP!", 19);
			ft_close(d);
		}
		x++;
	}
}

void	walls_check_columns(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->matrix[y])
	{
		if (d->matrix[y][x] != '1')
		{
			write(1, "ERROR: INVALID MAP!", 19);
			ft_close(d);
		}
		y++;
	}
	x = d->x_max - 1;
	y = 0;
	while (d->matrix[y])
	{
		if (d->matrix[y][x] != '1')
		{
			write(1, "ERROR: INVALID MAP!", 19);
			ft_close(d);
		}
		y++;
	}
}

void	element_check(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->matrix[y])
	{
		x = 0;
		while (d->matrix[y][x])
		{
			if (d->matrix[y][x] == 'C')
				d->a++;
			else if (d->matrix[y][x] == 'E')
				d->b++;
			else if (d->matrix[y][x] == 'P')
				d->c++;
			x++;
		}
		y++;
	}
	if (!d->a || !d->b || !d->c)
	{
		write(1, "ERROR: MISSING COIN, EXIT OR PLAYER\n", 37);
		ft_close(d);
	}
}
