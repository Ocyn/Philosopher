/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:59 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 18:22:08 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time_ms(t_time clock)
{
	return ((clock.tv_sec * 1000) + (clock.tv_usec / 1000));
}

void	ft_secure_print(long time, char *log, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->log);
	printf("%lu %ld %s\n", time, philo->number, log);
	pthread_mutex_unlock(&philo->data->log);
}

long	ft_time_diff(t_time start_unit, t_time new_unit)
{
	return (((new_unit.tv_sec * 1000) + (new_unit.tv_usec / 1000)) \
	- ((start_unit.tv_sec * 1000) + (start_unit.tv_usec / 1000)));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_secure_free(void *target)
{
	free(target);
	target = NULL;
}
