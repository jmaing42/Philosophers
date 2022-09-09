/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:12:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/10 00:59:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <pthread.h>

t_err	end(t_philo *self)
{
	size_t	i;

	i = -1;
	while (++i < self->number_of_philosophers)
	{
		if (pthread_mutex_lock(&self->philosopher[i].died_mutex))
			return (true);
		self->philosopher[i].died = true;
		if (pthread_mutex_unlock(&self->philosopher[i].died_mutex))
			return (true);
	}
	return (false);
}
