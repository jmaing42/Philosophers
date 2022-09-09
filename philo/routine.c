/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:46:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 16:15:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <pthread.h>

static void	*set_error(t_per_philosopher *per_philosopher)
{
	pthread_mutex_lock(&per_philosopher->philo->error_mutex);
	per_philosopher->philo->error = true;
	pthread_mutex_unlock(&per_philosopher->philo->error_mutex);
	return (NULL);
}

static t_err	initial_wait(t_per_philosopher *per_philosopher)
{
	per_philosopher->skip_turn = per_philosopher->skip_turn
		+ per_philosopher->philo->number_of_philosophers - 1;
	return (wrap_usleep(unit(per_philosopher->philo) * 1000));
}

void	*routine(t_per_philosopher *per_philosopher)
{
	if (per_philosopher->philo->number_of_philosophers % 2 == 0)
	{
		if (per_philosopher->index % 2 && initial_wait(per_philosopher))
			return (set_error(per_philosopher));
		while (1)
			if (even_routine(per_philosopher))
				return (set_error(per_philosopher));
	}
	else
	{
		if (per_philosopher->index == 1)
		{
			if (wrap_usleep(unit(per_philosopher->philo)))
				return (set_error(per_philosopher));
			per_philosopher->skip_turn = 0;
		}
		if (per_philosopher->index % 2 && initial_wait(per_philosopher))
			return (set_error(per_philosopher));
		while (1)
			if (odd_routine(per_philosopher))
				return (set_error(per_philosopher));
	}
	return (NULL);
}
