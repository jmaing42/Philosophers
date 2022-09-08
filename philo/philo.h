/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:38:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 06:51:37 by Juyeong Maing    ###   ########.fr       */
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
	size_t			number_of_rest_times_must_eat;
	struct s_philo	*philo;
	size_t			index;
	struct timeval	last_ate_time;
	bool			alive;
	pthread_mutex_t	last_ate_time_mutex;
	pthread_mutex_t	alive_mutex;
	size_t			skip_turn;
}	t_per_philosopher;

typedef struct s_philo
{
	size_t				number_of_philosophers;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				number_of_times_each_philosopher_must_eat;
	bool				error;
	pthread_mutex_t		error_mutex;
	t_per_philosopher	philosopher[];
}	t_philo;

t_err			init(int argc, char **argv, t_philo **out);
void			*philosopher(void *per_philosopher);

struct timeval	tv(size_t z);
struct timeval	add(struct timeval lhs, struct timeval rhs);
struct timeval	sub(struct timeval lhs, struct timeval rhs);
useconds_t		z(struct timeval tv);

#endif
