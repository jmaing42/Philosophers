/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:38:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 18:22:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# include "ft_types.h"

typedef struct s_per_philosopher
{
	pthread_t		philosopher;
	pthread_mutex_t	fork;
	volatile size_t	number_of_rest_times_must_eat;
	struct s_philo	*philo;
	size_t			index;
	struct timeval	last_ate;
	volatile bool	died;
	pthread_mutex_t	number_of_rest_times_must_eat_mutex;
	pthread_mutex_t	last_ate_mutex;
	pthread_mutex_t	died_mutex;
	size_t			skip_turn;
}	t_per_philosopher;

typedef struct s_philo
{
	size_t				number_of_philosophers;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				number_of_times_each_philosopher_must_eat;
	struct timeval		started;
	volatile bool		error;
	pthread_mutex_t		error_mutex;
	t_per_philosopher	philosopher[];
}	t_philo;

t_err			init(int argc, char **argv, t_philo **out);
t_err			monitor(t_philo *self);
t_err			end(t_philo *self);

useconds_t		unit(t_philo *philo);
t_err			wait_until(struct timeval until);
t_err			wrap_usleep(useconds_t microseconds);

void			*routine(t_per_philosopher *per_philosopher);
t_err			taken(t_per_philosopher *self);
t_err			eating(t_per_philosopher *self);
t_err			sleeping(t_per_philosopher *self);
t_err			thinking(t_per_philosopher *self, struct timeval start);

struct timeval	tv(size_t z);
struct timeval	add(struct timeval lhs, struct timeval rhs);
struct timeval	sub(struct timeval lhs, struct timeval rhs);
bool			is_bigger_than(struct timeval smaller, struct timeval bigger);
useconds_t		z(struct timeval tv);

#endif
