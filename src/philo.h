/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:51:43 by jcuzin            #+#    #+#             */
/*   Updated: 2023/12/19 19:33:51 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct timeval	t_time;

typedef struct s_philo
{
	t_data				*data;
	pthread_t			th_id;
	int					temp;
	t_time				expire;
	long				last_eat;
	long				is_dead;
	int					nb_eat;
	long				number;
	int					l_fork;
	int					r_fork;
}	t_philo;

typedef struct s_data
{
	t_philo				*philo;
	char				**input;
	pthread_mutex_t		*fork;
	pthread_mutex_t		sync;
	pthread_mutex_t		log;
	pthread_mutex_t		death;
	pthread_mutex_t		tick;
	pthread_mutex_t		last_eat;
	t_time				start_sim;
	int					phil_nb;
	int					mutex_chk;
	long				is_dead;
	int					i;
	long				t_eat;
	long				t_sleep;
	long				t_die;
	int					nb_eat;
	int					arg_nb;
}	t_data;

size_t			ft_strlen(char *str);
int				ft_init(int nb, char **arg, t_data *data);
void			ft_error_log(char *log, t_data *data);
int				ft_parse(t_data *data);
int				ft_init_threads(t_data *data, t_philo *philo);
void			*ft_philo(void *v_data);
int				ft_is_lock(pthread_mutex_t	*mutex);
void			ft_secure_free(void *target);
void			ft_bzero(void *str0, size_t n);
void			ft_ending(t_data *data);
void			ft_sleep(long ms_time);
void			ft_living_log(int eat, char *log, int time, t_philo *philo);
long			ft_time_diff(t_time start_unit, t_time new_unit);
long			ft_get_time_ms(t_time clock);
void			ft_secure_print(long time, char *log, t_philo *philo);
int				ft_isdied(t_data *data);
int				ft_nbeat(t_philo *philo);
void			ft_set_philo(t_philo *philo, t_data *data);
int				ft_stateof_philo(t_philo *philo);
long			ft_timestamp(t_philo *philo);
int				ft_mutex_setup(int operation, t_data *data);
void			ft_optimised_fork_check(int mode, t_philo *philo);

int				ft_atoi(const char *str);

void			db_philo_logs(int log, t_philo *philo);
void			db_display_var(char type, void *display);
void			db_t_data_display(t_data *data, int option);
void			db_t_philo_display(t_philo *philo, int option);

#endif