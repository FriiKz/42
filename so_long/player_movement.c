/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:17:30 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/22 17:37:42 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_counter(t_data *d)
{
	d->moves = ft_itoa(d->counter++);
	mlx_put_image_to_window(d->mlx, d->win, d->floor, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->tree, 0, 0);
	mlx_string_put(d->mlx, d->win, 0, 0, 0xff0000, d->moves);
	free(d->moves);
	return (0);
}

int	ft_movement(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->floor, d->x_p, d->y_p);
	if (d->key == 13)
		d->y_p -= 64;
	if (d->key == 0)
		d->x_p -= 64;
	if (d->key == 1)
		d->y_p += 64;
	if (d->key == 2)
		d->x_p += 64;
	move_counter(d);
	p_animation(d);
	enemy_tp(d);
	return (0);
}

int	p_animation(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->floor, d->x_p, d->y_p);
	if (d->key == 13)
		mlx_put_image_to_window(d->mlx, d->win, d->pb, d->x_p, d->y_p);
	if (d->key == 0)
		mlx_put_image_to_window(d->mlx, d->win, d->pl, d->x_p, d->y_p);
	if (d->key == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->pf, d->x_p, d->y_p);
	if (d->key == 2)
		mlx_put_image_to_window(d->mlx, d->win, d->pr, d->x_p, d->y_p);
	return (0);
}

int	check_input(int key, t_data *d)
{
	d->key = key;
	if (d->key == 53)
		ft_close(d);
	if (d->key == 13)
		collisions_w(d);
	if (d->key == 0)
		collisions_a(d);
	if (d->key == 1)
		collisions_s(d);
	if (d->key == 2)
		collisions_d(d);
	return (0);
}
