/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:18:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/10 00:53:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

t_err	sleeping(t_per_philosopher *self)
{
	struct timeval				now;
	t_philo *const				philo = self->philo;
	t_per_philosopher *const	next = &philo->philosopher[(self->index + 1)
		% philo->number_of_philosophers];

	return (
		false
		|| pthread_mutex_unlock(&self->fork)
		|| pthread_mutex_unlock(&next->fork)
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| gettimeofday(&now, NULL)
		|| printf(
			"%zu %zu is sleeping\n",
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index
		) < 0
		|| usleep(philo->time_to_sleep * 1000)
	);
}
