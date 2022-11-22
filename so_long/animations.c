/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:37:35 by aliburdi          #+#    #+#             */
/*   Updated: 2022/11/22 17:42:08 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kid_animation(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (d->matrix[y])
	{
		x = 0;
		while (d->matrix[y][x])
		{
			if (d->matrix[y][x] == 'E')
				animation(d, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	animation1(t_data *d, int x, int y)
{
	if (d->time == 0)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid8, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 1)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid7, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 2)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid6, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 3)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid5, x * 64, y * 64);
		d->time++;
	}
}

void	animation2(t_data *d, int x, int y)
{
	if (d->time == 4)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid4, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 5)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid3, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 6)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid2, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 7)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid1, x * 64, y * 64);
		d->time++;
	}
}

void	animation3(t_data *d, int x, int y)
{
	if (d->time == 8)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid2, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 9)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid3, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 10)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid4, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 11)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid5, x * 64, y * 64);
		d->time++;
	}
}

void	animation4(t_data *d, int x, int y)
{
	if (d->time == 12)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid6, x * 64, y * 64);
		d->time++;
	}
	else if (d->time == 13)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->floor, x * 64, y * 64);
		mlx_put_image_to_window(d->mlx, d->win, d->kid7, x * 64, y * 64);
		d->time = 0;
	}
}
