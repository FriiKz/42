/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:06 by aliburdi          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:12 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_tp(t_data *d)
{
	if (d->counter % 7 == 0 || d->counter % 11 == 0)
	{
		if (d->y_pmat + 2 < d->y_max
			&& d->matrix[d->y_pmat + 2][d->x_pmat] == '0')
		{
			d->matrix[d->y_pmat + 2][d->x_pmat] = 'N';
			mlx_put_image_to_window(d->mlx, d->win, d->n, d->x_p, d->y_p + 128);
		}
		if (d->key == 2 && d->matrix[d->y_pmat][d->x_pmat + 1] == '0')
		{
			d->matrix[d->y_pmat][d->x_pmat + 1] = 'N';
			mlx_put_image_to_window(d->mlx, d->win, d->n, d->x_p + 64, d->y_p);
		}
		if (d->key == 13 && d->matrix[d->y_pmat - 1][d->x_pmat] == '0')
		{
			d->matrix[d->y_pmat - 1][d->x_pmat] = 'N';
			mlx_put_image_to_window(d->mlx, d->win, d->n, d->x_p, d->y_p - 64);
		}
		if (d->key == 0 && d->matrix[d->y_pmat][d->x_pmat - 1] == '0')
		{
			d->matrix[d->y_pmat][d->x_pmat - 1] = 'N';
			mlx_put_image_to_window(d->mlx, d->win, d->n, d->x_p - 64, d->y_p);
		}
	}
}
