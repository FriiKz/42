/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:46:36 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/17 18:26:12 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->num_philo)
	{
		pthread_mutex_init(&room->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < room->num_philo)
	{
		room->philos[i].l_fork = &room->forks[i];
		room->philos[i].r_fork = &room->forks[(i + 1) % room->num_philo];
		i++;
	}
	return (0);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	write_action("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	write_action("has taken a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	write_action("is sleeping", philo);
	ft_usleep(philo->room->time_to_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->is_eating = 1;
	philo->time_last_meal = get_time() + philo->room->time_to_die;
	write_action("is eating", philo);
	philo->eat_count++;
	ft_usleep(philo->room->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}
