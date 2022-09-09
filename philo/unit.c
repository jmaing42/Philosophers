/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:00:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 12:50:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

useconds_t	unit(t_philo *philo)
{
	useconds_t	result;

	result = (philo->time_to_eat + philo->time_to_sleep + 1) / 2;
	if (result < philo->time_to_eat)
		result = philo->time_to_eat;
	return (result);
}
