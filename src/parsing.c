/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:53:50 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/07 01:29:59 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_start_time(void)
{
	t_time	time_s;

	if (gettimeofday(&time_s, NULL) == 0)
	{
		return ((time_s.tv_sec * 1000) \
		+ (time_s.tv_usec * 0.001));
	}
	else
		return (-1);
}

int	ft_parse(t_data *data)
{
	int	i;

	i = 0;
	if (data->arg_nb != 5 && data->arg_nb != 4)
		return (-1);
	data->phil_nb = ft_atoi(data->input[0]);
	data->t_die = ft_atoi(data->input[1]);
	data->t_eat = ft_atoi(data->input[2]);
	data->t_sleep = ft_atoi(data->input[3]);
	data->is_dead = 0;
	if (data->arg_nb == 5)
		data->nb_eat = ft_atoi(data->input[4]);
	else
		data->nb_eat = -1;
	if (!data->phil_nb || !data->t_die || !data->t_eat || !data->t_sleep)
		return (-1);
	return (0);
}
