/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:04:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 13:08:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	wait_until(struct timeval until)
{
	struct timeval	now;

	return (
		false
		|| gettimeofday(&now, NULL)
		|| (is_bigger_than(now, until) && usleep(z(sub(until, now))))
	);
}
