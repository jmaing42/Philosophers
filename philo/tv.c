/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:41:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 13:06:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <sys/time.h>

struct timeval	tv(size_t z)
{
	struct timeval	result;

	result.tv_sec = z / 1000000;
	result.tv_usec = z % 1000000;
	return (result);
}

struct timeval	add(struct timeval lhs, struct timeval rhs)
{
	struct timeval	result;

	result.tv_sec = lhs.tv_sec + rhs.tv_sec;
	result.tv_usec = lhs.tv_usec + rhs.tv_usec;
	result.tv_sec += result.tv_usec / 1000000;
	result.tv_usec %= 1000000;
	return (result);
}

struct timeval	sub(struct timeval lhs, struct timeval rhs)
{
	struct timeval	result;

	result.tv_sec = lhs.tv_sec - rhs.tv_sec - 1;
	result.tv_usec = lhs.tv_usec + 1000000 - rhs.tv_usec;
	result.tv_sec += result.tv_usec / 1000000;
	result.tv_usec %= 1000000;
	return (result);
}

bool	is_bigger_than(struct timeval smaller, struct timeval bigger)
{
	return (
		bigger.tv_sec > smaller.tv_sec
		|| (bigger.tv_sec == smaller.tv_sec && bigger.tv_usec > smaller.tv_usec)
	);
}

useconds_t	z(struct timeval tv)
{
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
