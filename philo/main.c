/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:34:28 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/17 18:37:26 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / (uint64_t)1000));
}

void	ft_close(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->num_philo)
	{
		pthread_mutex_destroy(&room->forks[i]);
		pthread_mutex_destroy(&room->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&room->write);
	pthread_mutex_destroy(&room->lock);
	clean_room(room);
}

int	init_threads(t_room *room)
{
	int			i;
	pthread_t	t1;

	i = -1;
	room->start = get_time();
	if (room->times_to_eat > 0)
	{
		if (pthread_create(&t1, NULL, &fifth_arg, &room->philos[0]))
			return (quit("Error\n", room));
	}
	while (++i < room->num_philo)
	{
		if (pthread_create(&room->tid[i], NULL, &routine, &room->philos[i]))
			return (quit("Error during philo creation\n", room));
		ft_usleep(1);
	}
	i = -1;
	while (++i < room->num_philo)
	{
		if (pthread_join(room->tid[i], NULL))
			return (quit("Error\n", room));
	}
	return (0);
}

int	init_all(t_room *room, int argc, char **argv)
{
	if (init_room(room, argc, argv))
		return (1);
	if (room_malloc(room))
		return (1);
	if (init_forks(room))
		return (1);
	init_philos(room);
	return (0);
}

int	main(int argc, char **argv)
{
	t_room	room;

	if (argc < 5 || argc > 6)
		return (1);
	if (check_input(argv, &room))
		return (1);
	if (init_all(&room, argc, argv))
		return (1);
	if (room.num_philo == 1)
		return (one_philo(&room));
	if (init_threads(&room))
		return (1);
	ft_close(&room);
	return (0);
}
