/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:40:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 15:46:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

t_err	wrap_usleep(useconds_t microseconds)
{
	struct timeval	now;
	struct timeval	target;

	if (gettimeofday(&now, NULL))
		return (true);
	target = add(now, tv(microseconds));
	if (usleep(microseconds))
		return (true);
	return (wait_until(target));
}
