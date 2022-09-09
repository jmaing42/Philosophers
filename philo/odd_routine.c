/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:58:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 15:46:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static const char *const	g_taken = "%zu %zu has taken a fork\n";
static const char *const	g_eating = "%zu %zu is eating\n";
static const char *const	g_sleeping = "%zu %zu is sleeping\n";
static const char *const	g_thinking = "%zu %zu is thinking\n";

static t_err	taken(t_per_philosopher *self);
static t_err	eating(t_per_philosopher *self);
static t_err	sleeping(t_per_philosopher *self);
static t_err	thinking(t_per_philosopher *self, struct timeval start);

t_err	odd_routine(t_per_philosopher *self)
{
	struct timeval				start;
	t_philo *const				philo = self->philo;

	if (self->skip_turn == 0)
	{
		self->skip_turn = philo->number_of_philosophers - 1;
		return (wrap_usleep(unit(philo) * 1000));
	}
	self->skip_turn = (self->skip_turn + philo->number_of_philosophers - 2)
		% philo->number_of_philosophers;
	return (
		false
		|| gettimeofday(&start, NULL)
		|| taken(self)
		|| eating(self)
		|| sleeping(self)
		|| thinking(self, start)
	);
}

static t_err	taken(t_per_philosopher *self)
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
			g_taken,
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index)
		< 0
	);
}

static t_err	eating(t_per_philosopher *self)
{
	t_philo *const				philo = self->philo;
	t_per_philosopher *const	next = &philo->philosopher[(self->index + 1)
		% philo->number_of_philosophers];

	return (
		false
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| (self->index % 2 == 0 && pthread_mutex_lock(&self->fork))
		|| (self->index % 2 == 1 && pthread_mutex_lock(&next->fork))
		|| pthread_mutex_lock(&self->died_mutex)
		|| self->died
		|| pthread_mutex_unlock(&self->died_mutex)
		|| pthread_mutex_lock(&self->last_ate_mutex)
		|| gettimeofday(&self->last_ate, NULL)
		|| printf(
			g_eating,
			(size_t)z(sub(self->last_ate, philo->started)) / 1000,
			self->index
		) < 0
		|| pthread_mutex_unlock(&self->last_ate_mutex)
		|| wrap_usleep(philo->time_to_eat * 1000)
	);
}

static t_err	sleeping(t_per_philosopher *self)
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
			g_sleeping,
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index
		) < 0
		|| wrap_usleep(philo->time_to_sleep * 1000)
	);
}

static t_err	thinking(t_per_philosopher *self, struct timeval start)
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
			g_thinking,
			(size_t)z(sub(now, philo->started)) / 1000,
			self->index
		) < 0
		|| wait_until(add(start, tv(unit(philo) * 2)))
	);
}
