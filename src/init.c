/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:56:26 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 15:27:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_philo(t_philo *philo, t_data *data)
{
	int	index;

	index = 0;
	while (index < data->phil_nb)
	{
		philo[index].l_fork = index;
		philo[index].data = data;
		philo[index].r_fork = (index + 1) % data->phil_nb;
		philo[index].last_eat = 0;
		philo[index].nb_eat = data->nb_eat;
		philo[index].is_dead = 0;
		philo[index].number = index + 1;
		philo[index].th_id = 0;
		philo[index].temp = 0;
		index++;
	}
	if (data->phil_nb % 2 != 0)
		philo[0].temp = 100;
}

int	ft_mutex_setup(int operation, t_data *data)
{
	int	err;

	err = 0;
	if (operation == 1)
	{
		err += pthread_mutex_init(&data->sync, NULL);
		err += pthread_mutex_init(&data->last_eat, NULL);
		err += pthread_mutex_init(&data->log, NULL);
		err += pthread_mutex_init(&data->death, NULL);
		err += pthread_mutex_init(&data->tick, NULL);
		data->mutex_chk = 0;
	}
	else if (data->mutex_chk)
	{
		err += pthread_mutex_destroy(&data->sync);
		err += pthread_mutex_destroy(&data->last_eat);
		err += pthread_mutex_destroy(&data->log);
		err += pthread_mutex_destroy(&data->death);
		err += pthread_mutex_destroy(&data->tick);
	}
	return (err);
}

int	ft_init(int nb, char **arg, t_data *data)
{
	int	i;

	i = 0;
	data->arg_nb = 0;
	data->input = 0;
	data->arg_nb = nb - 1;
	data->input = arg + 1;
	data->fork = NULL;
	data->mutex_chk = 0;
	if (ft_parse(data) < 0)
		return (ft_error_log("Invalid command format", data), -1);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->phil_nb);
	if (!data->fork)
		return (-1);
	while (i < data->phil_nb)
		pthread_mutex_init(&data->fork[i++], NULL);
	if (ft_mutex_setup(1, data) == -1)
		return (ft_error_log("Malloc Failed", data), -1);
	return (0);
}
