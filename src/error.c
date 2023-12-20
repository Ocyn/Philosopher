/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:18:14 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 15:24:09 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_ending(t_data *data)
{
	ft_mutex_setup(-1, data);
	ft_secure_free(data->fork);
}

void	ft_error_log(char *log, t_data *data)
{
	write(STDERR_FILENO, "\nError:\nReason \"", 16);
	write(STDERR_FILENO, log, ft_strlen(log));
	write(STDERR_FILENO, "\"\n", 2);
	ft_ending(data);
}
