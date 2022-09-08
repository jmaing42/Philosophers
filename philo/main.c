/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:35:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 05:50:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (init(argc, argv, &philo))
		return (EXIT_FAILURE);
}
