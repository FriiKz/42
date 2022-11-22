/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:40:25 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/22 17:37:10 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initializer(t_data *d)
{
	d->size = 64;
	d->mlx = mlx_init();
	d->x_max = column_counter(d);
	d->y_max = line_counter(d);
	d->x_pmat = 0;
	d->y_pmat = 0;
	d->win = mlx_new_window(d->mlx, d->x_max * 64, d->y_max * 64, "Slender");
	d->floor = mlx_xpm_file_to_image(d->mlx, "xpm/bg.xpm", &d->size, &d->size);
	d->tree = mlx_xpm_file_to_image(d->mlx, "xpm/tree.xpm", &d->size, &d->size);
	d->page = mlx_xpm_file_to_image(d->mlx, "xpm/page.xpm", &d->size, &d->size);
	d->pf = mlx_xpm_file_to_image(d->mlx, "xpm/pfront.xpm", &d->size, &d->size);
	d->pl = mlx_xpm_file_to_image(d->mlx, "xpm/pleft.xpm", &d->size, &d->size);
	d->pr = mlx_xpm_file_to_image(d->mlx, "xpm/pright.xpm", &d->size, &d->size);
	d->pb = mlx_xpm_file_to_image(d->mlx, "xpm/pback.xpm", &d->size, &d->size);
	d->n = mlx_xpm_file_to_image(d->mlx, "xpm/sle.xpm", &d->size, &d->size);
	d->x_p = 0;
	d->y_p = 0;
	d->counter = 1;
	d->time = 0;
	d->a = 0;
	d->b = 0;
	d->c = 0;
}

void	animation_initializer(t_data *d)
{
	d->kid1 = mlx_xpm_file_to_image(d->mlx, "xpm/kid1.xpm", &d->size, &d->size);
	d->kid2 = mlx_xpm_file_to_image(d->mlx, "xpm/kid2.xpm", &d->size, &d->size);
	d->kid3 = mlx_xpm_file_to_image(d->mlx, "xpm/kid3.xpm", &d->size, &d->size);
	d->kid4 = mlx_xpm_file_to_image(d->mlx, "xpm/kid4.xpm", &d->size, &d->size);
	d->kid5 = mlx_xpm_file_to_image(d->mlx, "xpm/kid5.xpm", &d->size, &d->size);
	d->kid6 = mlx_xpm_file_to_image(d->mlx, "xpm/kid6.xpm", &d->size, &d->size);
	d->kid7 = mlx_xpm_file_to_image(d->mlx, "xpm/kid7.xpm", &d->size, &d->size);
	d->kid8 = mlx_xpm_file_to_image(d->mlx, "xpm/kid8.xpm", &d->size, &d->size);
}

int	ft_close(t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	free_matrix(d);
	exit (0);
	return (0);
}

void	fd_check(t_data *d)
{
	if (ft_strcmp(d->map, ".ber"))
	{
		write(1, "ERROR: INVALID MAP ARGUMENT\n", 28);
	}
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		return (0);
	d.map = av[1];
	fd_check(&d);
	initializer(&d);
	animation_initializer(&d);
	if (d.x_max == d.y_max)
	{
		write(1, "ERROR: SQUARE MAP\n", 18);
		return (0);
	}
	matrix_c(&d);
	check_characters(&d);
	map_check(&d);
	player_xy(&d);
	walls_check_lines(&d);
	walls_check_columns(&d);
	element_check(&d);
	mlx_hook(d.win, 2, 1L << 0, check_input, &d);
	mlx_hook(d.win, 17, 1L << 16, ft_close, &d);
	mlx_loop_hook(d.mlx, kid_animation, &d);
	mlx_loop(d.mlx);
}
