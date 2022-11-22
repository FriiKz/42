/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:07:18 by aliburdi          #+#    #+#             */
/*   Updated: 2022/11/22 16:51:40 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collisions_w(t_data *d)
{
	if (d->matrix[d->y_pmat - 1][d->x_pmat] == '1' ||
		d->matrix[d->y_pmat - 1][d->x_pmat] == 'E')
	{
		if (coins_check(d) && d->matrix[d->y_pmat - 1][d->x_pmat] == 'E')
		{
			ft_movement(d);
			write(1, "YOU ESCAPED!\n(this time)\n", 25);
			ft_close(d);
		}
		move_counter(d);
		p_animation(d);
		return ;
	}
	if (d->matrix[d->y_pmat - 1][d->x_pmat] == 'N')
	{
		move_counter(d);
		write(1, "BETTER LUCK NEXT TIME\n", 23);
		ft_close(d);
	}
	d->matrix[d->y_pmat][d->x_pmat] = '0';
	d->matrix[d->y_pmat - 1][d->x_pmat] = 'P';
	d->y_pmat--;
	ft_movement(d);
}

void	collisions_a(t_data *d)
{
	if (d->matrix[d->y_pmat][d->x_pmat - 1] == '1' ||
		d->matrix[d->y_pmat][d->x_pmat - 1] == 'E')
	{
		if (coins_check(d) && d->matrix[d->y_pmat][d->x_pmat - 1] == 'E')
		{
			ft_movement(d);
			write(1, "YOU ESCAPED!\n(this time)\n", 25);
			ft_close(d);
		}
		move_counter(d);
		p_animation(d);
		return ;
	}
	if (d->matrix[d->y_pmat][d->x_pmat - 1] == 'N')
	{
		move_counter(d);
		write(1, "YOU SUCK!\n", 10);
		ft_close(d);
	}
	d->matrix[d->y_pmat][d->x_pmat] = '0';
	d->matrix[d->y_pmat][d->x_pmat - 1] = 'P';
	d->x_pmat--;
	ft_movement(d);
}

void	collisions_s(t_data *d)
{
	if (d->matrix[d->y_pmat + 1][d->x_pmat] == '1' ||
		d->matrix[d->y_pmat + 1][d->x_pmat] == 'E')
	{
		if (coins_check(d) && d->matrix[d->y_pmat + 1][d->x_pmat] == 'E')
		{
			ft_movement(d);
			write(1, "YOU ESCAPED!\n(this time)\n", 25);
			ft_close(d);
		}
		move_counter(d);
		p_animation(d);
		return ;
	}
	if (d->matrix[d->y_pmat + 1][d->x_pmat] == 'N')
	{
		move_counter(d);
		write(1, "GOT YOU!\n", 9);
		ft_close(d);
	}
	d->matrix[d->y_pmat][d->x_pmat] = '0';
	d->matrix[d->y_pmat + 1][d->x_pmat] = 'P';
	d->y_pmat++;
	ft_movement(d);
}

void	collisions_d(t_data *d)
{
	if (d->matrix[d->y_pmat][d->x_pmat + 1] == '1' ||
		d->matrix[d->y_pmat][d->x_pmat + 1] == 'E')
	{
		if (coins_check(d) && d->matrix[d->y_pmat][d->x_pmat + 1] == 'E')
		{
			ft_movement(d);
			write(1, "YOU ESCAPED!\n(this time)\n", 25);
			ft_close(d);
		}
		move_counter(d);
		p_animation(d);
		return ;
	}
	if (d->matrix[d->y_pmat][d->x_pmat + 1] == 'N')
	{
		move_counter(d);
		write(1, "GET GOOD LOSER!\n", 16);
		ft_close(d);
	}
	d->matrix[d->y_pmat][d->x_pmat] = '0';
	d->matrix[d->y_pmat][d->x_pmat + 1] = 'P';
	d->x_pmat++;
	ft_movement(d);
}

int	coins_check(t_data *d)
{
	d->x_coin = 0;
	d->y_coin = 0;
	while (d->matrix[d->y_coin])
	{
		d->x_coin = 0;
		while (d->matrix[d->y_coin][d->x_coin])
		{
			if (d->matrix[d->y_coin][d->x_coin] == 'C')
				return (0);
			d->x_coin++;
		}
		d->y_coin++;
	}
	return (1);
}
