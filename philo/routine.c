/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:10:24 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/17 17:54:30 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->time_last_meal = philo->room->time_to_die + get_time();
	if (pthread_create(&philo->thread, NULL, &check_death, (void *)philo))
		return ((void *)1);
	while (philo->room->death == 0)
	{
		eat(philo);
		write_action("is thinking", philo);
	}
	if (pthread_join(philo->thread, NULL))
		return ((void *)1);
	return ((void *)0);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->room->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_last_meal && philo->is_eating == 0)
			write_action("died", philo);
		if (philo->eat_count == philo->room->times_to_eat)
		{
			pthread_mutex_lock(&philo->room->lock);
			philo->eat_count++;
			philo->room->end++;
			pthread_mutex_unlock(&philo->room->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*fifth_arg(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->room->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->room->end >= philo->room->num_philo)
			philo->room->death = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

int	one_philo(t_room *room)
{
	room->start = get_time();
	if (pthread_create(&room->tid[0], NULL, &routine, &room->philos[0]))
		return (quit("Error", room));
	pthread_detach(room->tid[0]);
	while (room->death == 0)
		ft_usleep(0);
	ft_close(room);
	return (0);
}
