/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:18:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 18:35:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <pthread.h>

t_err	eating(t_per_philosopher *self)
{
	t_philo *const				philo = self->philo;
	t_per_philosopher *const	next = &philo->philosopher[(self->index + 1)
		% philo->number_of_philosophers];

	if (pthread_mutex_lock(&self->died_mutex) || self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| (self->index % 2 == 0 && pthread_mutex_lock(&self->fork))
		|| (self->index % 2 == 1 && pthread_mutex_lock(&next->fork))
		|| pthread_mutex_lock(&self->died_mutex) || self->died
		|| pthread_mutex_unlock(&self->died_mutex) || pthread_mutex_lock
		(&self->last_ate_mutex) || gettimeofday(&self->last_ate, NULL)
		|| printf("%zu %zu is eating\n", (size_t)
			z(sub(self->last_ate, philo->started)) / 1000, self->index) < 0
		|| pthread_mutex_unlock(&self->last_ate_mutex) || pthread_mutex_lock(
			&self->number_of_rest_times_must_eat_mutex))
		return (true);
	if (self->number_of_rest_times_must_eat != (size_t)-1)
		self->number_of_rest_times_must_eat--;
	if (
		pthread_mutex_unlock(&self->number_of_rest_times_must_eat_mutex)
		|| wrap_usleep(philo->time_to_eat * 1000)
	)
		return (true);
	return (false);
}
