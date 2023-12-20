/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 06:45:02 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 19:36:15 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_optimised_fork_drop(t_philo *philo)
{
	if (philo->number % 2 != 0)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
	}
}

int	ft_optimised_fork_take(t_philo *philo)
{
	if (philo->number % 2 != 0)
	{
		pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
		ft_living_log(0, "has taken a fork", 0, philo);
		pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
		ft_living_log(0, "has taken a fork", 0, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
		ft_living_log(0, "has taken a fork", 0, philo);
		pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
		ft_living_log(0, "has taken a fork", 0, philo);
	}
	return (0);
}

int	ft_stateof_philo(t_philo *philo)
{
	t_time		latency;
	long		delta;

	gettimeofday(&latency, NULL);
	pthread_mutex_lock(&philo->data->last_eat);
	delta = ft_time_diff(philo->expire, latency);
	pthread_mutex_unlock(&philo->data->last_eat);
	if (philo->data->is_dead == 0)
	{
		if (delta >= philo->data->t_die)
		{
			pthread_mutex_lock(&philo->data->log);
			pthread_mutex_lock(&philo->data->death);
			philo->data->is_dead = 1;
			printf("%lu %ld died\n", \
			ft_time_diff(philo->data->start_sim, latency), philo->number);
			pthread_mutex_unlock(&philo->data->death);
			pthread_mutex_unlock(&philo->data->log);
			usleep(200);
			return (-1);
		}
	}
	return (0);
}

void	ft_living_log(int eat, char *log, int time, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->log);
	if (ft_isdied(philo->data) == 0)
	{
		printf("%lu %ld %s\n", ft_timestamp(philo), philo->number, log);
		pthread_mutex_unlock(&philo->data->log);
		if (eat == 1)
		{
			pthread_mutex_lock(&philo->data->last_eat);
			gettimeofday(&philo->expire, NULL);
			pthread_mutex_unlock(&philo->data->last_eat);
		}
		if (time > 0)
			ft_sleep(time);
		return ;
	}
	pthread_mutex_unlock(&philo->data->log);
}

void	*ft_philo(void *v_data)
{
	t_philo			*philo;

	philo = (t_philo *)v_data;
	pthread_mutex_lock(&philo->data->sync);
	pthread_mutex_unlock(&philo->data->sync);
	pthread_mutex_lock(&philo->data->last_eat);
	gettimeofday(&philo->expire, NULL);
	ft_living_log(0, "is thinking", 0, philo);
	pthread_mutex_unlock(&philo->data->last_eat);
	if (philo->number % 2 != 0)
		usleep(((philo->data->t_eat) * 1000) + philo->temp);
	while (ft_isdied(philo->data) == 0 && ft_nbeat(philo) \
	&& philo->l_fork != philo->r_fork)
	{
		ft_optimised_fork_take(philo);
		ft_living_log(1, "is eating", philo->data->t_eat, philo);
		ft_optimised_fork_drop(philo);
		pthread_mutex_lock(&philo->data->tick);
		philo->nb_eat--;
		pthread_mutex_unlock(&philo->data->tick);
		ft_living_log(0, "is sleeping", philo->data->t_sleep, philo);
		if (philo->nb_eat != 0)
			ft_living_log(0, "is thinking", 0, philo);
	}
	return (NULL);
}
