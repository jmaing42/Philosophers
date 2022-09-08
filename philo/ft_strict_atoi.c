/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/21 23:23:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strict_atoi.h"

#include <limits.h>

t_err	ft_strict_atoi(const char *str, int *out)
{
	int	sgn;
	int	result;

	if (!str[0]
		|| (str[0] == '-' && !str[1])
		|| (str[0] == '-' && str[1] == '0')
		|| (str[0] == '0' && str[1]))
		return (true);
	result = 0;
	sgn = 1;
	if (*str == '-' && *str++)
		sgn = -1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9')
			|| result > INT_MAX / 10 || result < INT_MIN / 10
			|| (result == INT_MAX / 10
				&& (*str - '0') > (INT_MAX % 10))
			|| (result == INT_MIN / 10
				&& (*str - '0') > -(INT_MIN % 10)))
			return (true);
		result = result * 10 + (*str++ - '0') * sgn;
	}
	*out = result;
	return (false);
}
