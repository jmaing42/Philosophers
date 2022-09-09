/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:18:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 18:21:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <pthread.h>

t_err	thinking(t_per_philosopher *self, struct timeval start)
{
	struct timeval				now;
	t_philo *const				philo = self->philo;

	return (
		false
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| gettimeofday(&now, NULL)
		|| printf(
			"%zu %zu is thinking\n",
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index
		) < 0
		|| wait_until(add(start, tv(unit(philo) * 2)))
	);
}
