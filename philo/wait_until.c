/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:04:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 15:57:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	wait_until(struct timeval until)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (true);
	while (is_bigger_than(now, until))
		if (wrap_usleep(z(sub(until, now)) * 8 / 10))
			return (true);
	return (false);
}
