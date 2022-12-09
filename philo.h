/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofallahi <mofallahi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:09:18 by mofallahi         #+#    #+#             */
/*   Updated: 2022/12/09 15:26:00 by mofallahi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_gp
{
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_m_eat;
}	t_gp;

typedef struct s_philo
{
	t_gp				*gp;
	int					alive;
	int					id;
	int					nb_eat;
	unsigned long		last_meal;
	pthread_t			thread_id;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	pthread_mutex_t		print;
}	t_philo;

long long				ft_atoi(char *str);
int						ft_right_data(int ac, char **av);
int						init(char **str, t_gp *gp, t_philo *philo);
int						create(t_philo	*philo);
void					*routine(void *data);
void					ft_printf(t_philo *philo, char *str);
unsigned long			ft_time(void);
int						trackker(t_philo *philo);
void					ft_usleep(unsigned long x);

#endif