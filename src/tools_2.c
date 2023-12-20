/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:13:24 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 19:36:00 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_result(const char *str, size_t index)
{
	int	result;

	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10;
		result = result + str[index++] - 48;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	size_t	index;
	int		sign;
	int		symb_count;

	index = 0;
	sign = 1;
	symb_count = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (symb_count > 1)
			return (0);
		if (str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-')
				sign *= -1;
			symb_count++;
			index++;
		}
	}
	if (symb_count > 1)
		return (0);
	return (ft_print_result(str, index) * sign);
}

long	ft_timestamp(t_philo *philo)
{
	t_time	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	return (((current_time.tv_sec * 1000) \
	- (philo->data->start_sim.tv_sec * 1000)) \
	+ (current_time.tv_usec / 1000) \
	- (philo->data->start_sim.tv_usec / 1000));
}

void	ft_sleep(long ms_time)
{
	t_time	start_unit;
	t_time	new_unit;

	gettimeofday(&start_unit, NULL);
	gettimeofday(&new_unit, NULL);
	while ((new_unit.tv_sec * 1000 + new_unit.tv_usec / 1000) - \
	(start_unit.tv_sec * 1000 + start_unit.tv_usec / 1000) < ms_time)
	{
		usleep(200);
		gettimeofday(&new_unit, NULL);
	}
}

void	ft_optimised_fork_check(int mode, t_philo *philo)
{
	if (philo->number % 2 != 0 || mode == 1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
	}
	else if (mode == 2)
	{
		pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	}
}
