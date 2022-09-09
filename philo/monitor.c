/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:54:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 18:36:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <pthread.h>

static t_err	check_die(t_philo *self)
{
	size_t			i;
	struct timeval	now;

	i = -1;
	while (++i < self->number_of_philosophers)
	{
		if (pthread_mutex_lock(&self->philosopher[i].last_ate_mutex)
			|| gettimeofday(&now, NULL))
			return (true);
		if (is_bigger_than(add(
					self->philosopher[i].last_ate,
					tv(self->time_to_die * 1000)),
				now))
		{
			printf("%zu %zu is died\n",
				(size_t)z(sub(now, self->started)) / 1000, i);
			end(self);
			return (true);
		}
		if (pthread_mutex_unlock(&self->philosopher[i].last_ate_mutex))
			return (true);
	}
	return (false);
}

static t_err	check_count(t_philo *self)
{
	size_t			i;
	bool			all_ok;

	if (self->number_of_times_each_philosopher_must_eat == (size_t)-1)
		return (false);
	all_ok = true;
	i = -1;
	while (++i < self->number_of_philosophers)
	{
		if (pthread_mutex_lock(
				&self->philosopher[i].number_of_rest_times_must_eat_mutex))
			return (true);
		if (self->philosopher[i].number_of_rest_times_must_eat != 0)
			all_ok = false;
		if (pthread_mutex_unlock(
				&self->philosopher[i].number_of_rest_times_must_eat_mutex))
			return (true);
		if (all_ok)
		{
			end(self);
			return (true);
		}
	}
	return (false);
}

t_err	monitor(t_philo *self)
{
	while (1)
	{
		if (
			false
			|| check_die(self)
			|| check_count(self)
		)
			return (true);
	}
}
