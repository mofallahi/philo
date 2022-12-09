/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofallahi <mofallahi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:09:03 by mofallahi         #+#    #+#             */
/*   Updated: 2022/12/09 16:00:55 by mofallahi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *str)
{
	int	i;
	int	ms;
	int	r;

	ms = 1;
	r = 0;
	i = 0;
	if (!str)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ms = ms * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (str[i] - 48) + (r * 10);
		i++;
	}
	if (str[i] != 0)
		return (0);
	return (r * ms);
}

void	ft_usleep(unsigned long x)
{
	long long x_0;
	
	x_0 = ft_time();
	while (ft_time() < x_0 + x)
		usleep(100);
}

// unsigned long	ft_time(void)
// {
// 	struct timeval			t_db;
// 	unsigned long			x;
// 	static unsigned long	x_0;

// 	gettimeofday(&t_db, NULL);
// 	x = t_db.tv_sec*1000 + t_db.tv_usec/1000;
// 	if (x_0 == 0)
// 		x_0 = x;
// 	return (x - x_0);
// }

unsigned long	ft_time(void)
{
	struct timeval			t_db;
	unsigned long			x;
	static unsigned long	x_0;

	gettimeofday(&t_db, NULL);
	x = t_db.tv_sec*1000 + t_db.tv_usec/1000;
	if (x_0 == 0)
		x_0 = x;
	return x - x_0;
}


// int	ft_right_data(int ac, char **av)
// {
// 	while (--ac)
// 		if (ft_atoi(av[ac]) <= 0)
// 			return (1);
// 	return (0);
// }

int	ft_right_data(int ac, char **av)
{
	
	while (--ac)
		if (ft_atoi(av[ac]) <= 0)
			return (1);
	return (0);
}



// void	ft_printf(t_philo *philo, char *str)
// {
// 	pthread_mutex_lock(&philo->print);
// 	if (philo->alive == 1)
// 		printf("%ld %d %s",ft_time(), philo->id, str);
// 	pthread_mutex_unlock(&philo->print);
// }

void	ft_printf(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->print);
	if (philo->alive == 1)
		printf("%ld %d %s",ft_time(), philo->id, str);
	pthread_mutex_unlock(&philo->print);
}

// int	create(t_philo	*philo)
// {
// 	int i;

// 	i = -1;
// 	while (++i < philo[0].gp->nb_philo)
// 		if(pthread_create(&philo[0].thread_id, NULL, &routine, &philo[i]))
// 			return (0);
// 	return (1);
// }

int	create(t_philo	*philo)
{
	int i;

	i = -1;
	while (++i < philo[0].gp->nb_philo)
		if(pthread_create(&philo[0].thread_id, NULL, &routine, &philo[i]))
			return (0);
	return (1);
}
