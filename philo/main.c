/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:35:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 17:14:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (
		false
		|| init(argc, argv, &philo)
		|| monitor(philo)
		|| end(philo)
	)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
