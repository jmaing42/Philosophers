/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:12:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 13:14:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <pthread.h>

t_err	join(t_philo *self)
{
	size_t	i;

	i = -1;
	while (++i < self->number_of_philosophers)
		if (pthread_join(self->philosopher[i].philosopher, NULL))
			return (true);
	return (false);
}
