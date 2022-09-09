/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:44:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 13:10:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

#include "ft_types.h"
#include "ft_strict_atoi.h"

t_err	init_philosophers(t_philo *out)
{
	size_t	i;

	i = -1;
	while (++i < out->number_of_philosophers)
	{
		out->philosopher[i].philo = out;
		out->philosopher[i].index = i;
		out->philosopher[i].number_of_rest_times_must_eat
			= out->number_of_times_each_philosopher_must_eat;
		out->philosopher[i].skip_turn = i;
		out->philosopher[i].died = false;
		if (out->number_of_philosophers % 2 == 0)
			out->philosopher[i].skip_turn %= 2;
		if (pthread_mutex_init(
				&out->philosopher[i].number_of_rest_times_must_eat_mutex, NULL)
			|| pthread_mutex_init(&out->philosopher[i].died_mutex, NULL)
			|| pthread_mutex_init(&out->philosopher[i].last_ate_mutex, NULL)
			|| pthread_mutex_init(&out->philosopher[i].fork, NULL)
			|| gettimeofday(&out->philosopher[i].last_ate, NULL)
			|| pthread_create(&out->philosopher[i].philosopher, NULL,
				(void *(*)(void *))routine, &out->philosopher[i]))
			return (true);
	}
	return (false);
}

t_err	init(int argc, char **argv, t_philo **out)
{
	int		tmp;

	if ((argc != 5 && argc != 6) || ft_strict_atoi(argv[1], &tmp) || tmp <= 0)
		return (true);
	*out = malloc(sizeof(t_philo) + tmp * sizeof(t_per_philosopher));
	(*out)->error = false;
	if (*out == NULL || pthread_mutex_init(&(*out)->error_mutex, NULL)
		|| gettimeofday(&(*out)->started, NULL))
		return (true);
	(*out)->number_of_philosophers = tmp;
	if (ft_strict_atoi(argv[2], &tmp) || tmp <= 0)
		return (true);
	(*out)->time_to_die = tmp;
	if (ft_strict_atoi(argv[3], &tmp) || tmp <= 0)
		return (true);
	(*out)->time_to_eat = tmp;
	if (ft_strict_atoi(argv[4], &tmp) || tmp <= 0)
		return (true);
	(*out)->time_to_sleep = tmp;
	if (argc == 6 && (ft_strict_atoi(argv[5], &tmp) || tmp <= 0))
		return (true);
	(*out)->number_of_times_each_philosopher_must_eat = tmp;
	if (argc != 6)
		(*out)->number_of_times_each_philosopher_must_eat = -1;
	return (init_philosophers(*out));
}
