/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:18:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/10 09:51:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <pthread.h>

t_err	taken(t_per_philosopher *self)
{
	struct timeval				now;
	t_philo *const				philo = self->philo;
	t_per_philosopher *const	next = &philo->philosopher[(self->index + 1)
		% philo->number_of_philosophers];

	return (
		false
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| (self->index % 2 == 0 && pthread_mutex_lock(&next->fork))
		|| (self->index % 2 == 1 && pthread_mutex_lock(&self->fork))
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| gettimeofday(&now, NULL)
		|| printf(
			"%zu %zu has taken a fork\n",
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index + 1)
		< 0
	);
}
