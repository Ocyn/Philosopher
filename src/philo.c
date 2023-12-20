/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:51:31 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 15:21:31 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_nbeat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->tick);
	if (philo->nb_eat == 0)
	{
		pthread_mutex_unlock(&philo->data->tick);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->tick);
	return (-1);
}

int	ft_isdied(t_data *data)
{
	pthread_mutex_lock(&data->death);
	if (data->is_dead == 0)
	{
		pthread_mutex_unlock(&data->death);
		return (0);
	}
	pthread_mutex_unlock(&data->death);
	return (-1);
}

int	ft_watchdog(t_philo *philo, t_data *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	usleep((data->t_die * 1000) / 2);
	while (ft_stateof_philo(&philo[i]) == 0 \
	&& ft_nbeat(&philo[i]) != 0)
		i = (i + 1) % data->phil_nb;
	data->i = 0;
	while (data->i < data->phil_nb)
	{
		pthread_join(philo[data->i].th_id, NULL);
		data->i++;
	}
	data->i = 0;
	while (data->i < data->phil_nb)
		pthread_mutex_destroy(&data->fork[data->i++]);
	ft_secure_free(philo);
	return (err);
}

int	ft_init_threads(t_data *data, t_philo *philo)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	data->i = 0;
	if (data->phil_nb >= 1)
		philo = malloc(sizeof(t_philo) * data->phil_nb);
	ft_set_philo(philo, data);
	i = 0;
	pthread_mutex_lock(&data->sync);
	while (i < data->phil_nb)
	{
		pthread_create(&philo[i].th_id, NULL, ft_philo, &philo[i]);
		i++;
	}
	gettimeofday(&data->start_sim, NULL);
	pthread_mutex_unlock(&data->sync);
	data->i = 0;
	err = ft_watchdog(philo, data);
	return (err);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_init(argc, argv, &data) < 0)
		return (-1);
	if (ft_init_threads(&data, data.philo) == 1)
		return (-1);
	ft_ending(&data);
	return (0);
}
