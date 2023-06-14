/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:34:40 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/17 17:53:30 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_room	*room;
	int				id;
	int				eat_count;
	int				is_eating;
	int				status;
	u_int64_t		time_last_meal;
	pthread_t		thread;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_room
{
	int				num_philo;
	int				times_to_eat;
	int				death;
	int				end;
	t_philo			*philos;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		time_to_die;
	u_int64_t		start;
	pthread_t		*tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_room;

int			init_forks(t_room *room);
int			init_threads(t_room *room);
int			init_room(t_room *room, int argc, char **argv);
int			room_malloc(t_room *room);
int			init_all(t_room *room, int argc, char **argv);
int			check_input(char **argv, t_room *room);
int			ft_usleep(useconds_t time);
int			ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			one_philo(t_room *room);
int			quit(char *str, t_room *room);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		eat(t_philo *philo);
void		write_action(char *str, t_philo *philo);
void		ft_close(t_room *room);
void		clean_room(t_room *room);
void		init_philos(t_room *room);
void		*routine(void *arg);
void		*check_death(void *arg);
void		*fifth_arg(void *arg);
u_int64_t	get_time(void);

#endif
