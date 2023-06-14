/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:35:03 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/17 18:32:27 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	room_malloc(t_room *room)
{
	room->tid = malloc(sizeof(pthread_t) * room->num_philo);
	if (!room->tid)
		return (quit("MALLOC Error\n", room));
	room->forks = malloc(sizeof(pthread_mutex_t) * room->num_philo);
	if (!room->forks)
		return (quit("MALLOC Error\n", room));
	room->philos = malloc(sizeof(t_philo) * room->num_philo);
	if (!room->philos)
		return (quit("MALLOC Error\n", room));
	return (0);
}

int	init_room(t_room *room, int argc, char **argv)
{
	room->num_philo = (int) ft_atoi(argv[1]);
	room->time_to_die = (u_int64_t) ft_atoi(argv[2]);
	room->time_to_eat = (u_int64_t) ft_atoi(argv[3]);
	room->time_to_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		room->times_to_eat = (int) ft_atoi(argv[5]);
	else
		room->times_to_eat = -1;
	if (room->num_philo > 200 || room->time_to_die < 0
		|| room->time_to_eat < 0 || room->time_to_sleep < 0
		|| room->num_philo < 1)
		return (quit("Wrong input", room));
	room->end = 0;
	room->death = 0;
	pthread_mutex_init(&room->lock, NULL);
	pthread_mutex_init(&room->write, NULL);
	return (0);
}

void	init_philos(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->num_philo)
	{
		room->philos[i].room = room;
		room->philos[i].id = i + 1;
		room->philos[i].time_last_meal = room->time_to_die;
		room->philos[i].is_eating = 0;
		room->philos[i].eat_count = 0;
		room->philos[i].status = 0;
		pthread_mutex_init(&room->philos[i].lock, NULL);
		i++;
	}
}

void	clean_room(t_room *room)
{
	if (room->tid)
		free(room->tid);
	if (room->forks)
		free(room->forks);
	if (room->philos)
		free(room->philos);
}

int	quit(char *str, t_room *room)
{
	printf("%s\n", str);
	if (room)
		ft_close(room);
	return (1);
}
