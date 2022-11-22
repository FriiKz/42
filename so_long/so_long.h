/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:30:00 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/22 17:51:00 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*tree;
	void	*page;
	void	*pl;
	void	*pr;
	void	*pf;
	void	*pb;
	void	*n;
	void	*kid1;
	void	*kid2;
	void	*kid3;
	void	*kid4;
	void	*kid5;
	void	*kid6;
	void	*kid7;
	void	*kid8;
	char	**matrix;
	char	*map;
	char	*moves;
	int		size;
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		x_p;
	int		y_p;
	int		x_pmat;
	int		y_pmat;
	int		x_coin;
	int		y_coin;
	int		counter;
	int		key;
	int		a;
	int		b;
	int		c;
	int		time;

}				t_data;

void	initializer(t_data *d);
void	map_check(t_data *d);
void	map_loader(char map, t_data *d);
void	free_matrix(t_data *d);
void	matrix_c(t_data *d);
void	player_xy(t_data *d);
void	collisions_w(t_data *d);
void	collisions_a(t_data *d);
void	collisions_s(t_data *d);
void	collisions_d(t_data *d);
void	walls_check_lines(t_data *d);
void	walls_check_columns(t_data *d);
void	element_check(t_data *d);
void	enemy_tp(t_data *d);
void	check_characters(t_data *d);
void	animation(t_data *d, int x, int y);
void	animation1(t_data *d, int x, int y);
void	animation2(t_data *d, int x, int y);
void	animation3(t_data *d, int x, int y);
void	animation4(t_data *d, int x, int y);
void	animation_initializer(t_data *d);
void	fd_check(t_data *d);
int		kid_animation(t_data *d);
int		move_counter(t_data *d);
int		ft_close(t_data *d);
int		line_counter(t_data *d);
int		column_counter(t_data *d);
int		check_input(int key, t_data *d);
int		ft_movement(t_data *d);
int		p_animation(t_data *d);
int		coins_check(t_data *d);
int		ft_numlen(int n, int base);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);

#endif