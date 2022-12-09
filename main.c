/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofallahi <mofallahi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:09:12 by mofallahi         #+#    #+#             */
/*   Updated: 2022/12/09 15:32:49 by mofallahi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	init(char **str, t_gp *grp, t_philo *philo)
// {
// 	int	i;

// 	i = -1;
// 	grp->nb_philo = ft_atoi(str[1]);
// 	grp->time_die = ft_atoi(str[2]);
// 	grp->time_eat = ft_atoi(str[3]);
// 	grp->time_sleep = ft_atoi(str[4]);
// 	grp->nb_m_eat = ft_atoi(str[5]);
// 	while (++i < grp->nb_philo)
// 	{
// 		philo[i].gp = grp;
// 		philo[i].id = i + 1;
// 		philo[i].alive = 1;
// 		philo[i].nb_eat = 0;
// 		philo[i].last_meal = 0;
// 		if (pthread_mutex_init(&philo[i].fork, NULL)
// 			||pthread_mutex_init(&philo[i].print, NULL))
// 			return (printf("Mutex error\n"));
// 		philo[i].next_fork = &philo[(i + 1) % grp->nb_philo].fork;
// 	}
// 	return (0);
// }


int	init(char **str, t_gp *grp, t_philo *philo)
{
	int	i;

	i = -1;
	grp->nb_philo = ft_atoi(str[1]);
	grp->time_die = ft_atoi(str[2]);
	grp->time_eat = ft_atoi(str[3]);
	grp->time_sleep = ft_atoi(str[4]);
	grp->nb_m_eat = ft_atoi(str[5]);
	while (++i < grp->nb_philo)
	{
		philo[i].gp = grp;
		philo[i].id = i + 1;
		philo[i].nb_eat = 0;
		philo[i].alive = 1;
		philo[i].last_meal = 0;
		if (pthread_mutex_init(&philo[i].fork, NULL) || pthread_mutex_init(&philo[i].print, NULL))
			return (printf("Mutex error\n"));
		philo[i].next_fork = &philo[(i + 1) % grp->nb_philo].fork;
	}
	return (0);
}


// void	*routine(void *data)
// {
// 	t_philo	*philo;

// 	philo = data;
// 	if (ft_time() == 0 && !(philo->id % 2))
// 		usleep(philo->gp->time_eat * 1000);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->fork);
// 		ft_printf(philo, "Took fork\n");
// 		pthread_mutex_lock(philo->next_fork);
// 		ft_printf(philo, "Took next fork\n");
// 		ft_printf(philo, "is eating\n");
// 		philo->last_meal = ft_time();
// 		usleep(philo->gp->time_eat * 1000);
// 		philo->nb_eat++;
// 		pthread_mutex_unlock(&philo->fork);
// 		pthread_mutex_unlock(philo->next_fork);
// 		ft_printf(philo, "is sleeping\n");
// 		usleep(philo->gp->time_sleep * 1000);
// 		ft_printf(philo, "is thinking\n");
// 	}
// 	return (NULL);
// }

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if (!ft_time() && philo->id % 2 == 0)
		ft_usleep(philo->gp->time_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		ft_printf(philo, "took a fork\n");
		pthread_mutex_lock(philo->next_fork);
		ft_printf(philo, "took next fork\n");
		ft_printf(philo, "is eating\n");
		philo->last_meal = ft_time();
		ft_usleep(philo->gp->time_eat * 1000);
		philo->nb_eat++;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		ft_printf(philo, "sleeping\n");
		ft_usleep(philo->gp->time_sleep * 1000);
		ft_printf(philo, "thinking\n");
	}
	return (NULL);
}


// int	trackker(t_philo *philo)
// {
// 	int	i;
// 	int	nb;

// 	nb = philo[0].gp->nb_philo;
// 	i = -1;
// 	while (++i < nb)
// 	{
// 		if (philo[i].gp->nb_m_eat != -1
// 			&& philo[i].gp->nb_m_eat == philo[i].nb_eat)
// 		{
// 			philo[i].alive = 0;
// 			return (pthread_mutex_lock(&philo[i].print));
// 		}
// 		if (philo[i].last_meal + philo[i].gp->time_die < ft_time())
// 		{
// 			ft_printf(&philo[i], "dead\n");
// 			return (pthread_mutex_lock(&philo[i].print));
// 		}
// 		if (i == nb - 1)
// 			i = -1;
// 		usleep(100);
// 	}
// 	return (0);
// }

int		trackker(t_philo *philo)
{
	int		i;
	

	i = -1;
	while (++i < philo[0].gp->nb_philo)
	{
		//printf("**** %d\n", i);
		if (philo[i].gp->nb_m_eat != -1 && philo[i].gp->nb_m_eat == philo[i].nb_eat)
			return (pthread_mutex_lock(&philo[i].print));
		if (philo[i].last_meal + philo[i].gp->time_die < ft_time())
		{
			ft_printf(&philo[i], "dead\n");
			return (pthread_mutex_lock(&philo[i].print));
		}
		if (i == philo[0].gp->nb_philo -1)
			i = -1;
		ft_usleep(100);
	}
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_philo	*philo;
// 	t_gp	grp;
// 	int		i;

// 	i = -1;
// 	philo = NULL;
// 	if (ac >= 5 && ac <= 6 && !ft_right_data(ac, av))
// 	{
// 		philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
// 		if (!philo)
// 			return (printf("Error Malloc"));
// 		if (init(av, &grp, philo))
// 			return (0);
// 		if (create(philo))
// 			return (0);
// 		trackker(philo);
// 		while(++i < philo->gp->nb_philo)
// 		{
// 			pthread_mutex_destroy(&philo[i].fork);
// 			pthread_mutex_destroy(&philo[i].print);
// 		}
// 		free(philo);
// 	}
// 	else
// 		return (printf("Error Arguments\n"));
// }


int main(int ac, char **av)
{
	t_philo			*philo;
	t_gp			grp;
	int				i;
	
	i = -1;
	philo = NULL;
	if (ac >= 5 && ac <= 6 && !ft_right_data(ac, av))
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		if (!philo)
			return (printf("Malloc error\n"));
		if (init(av, &grp, philo))
			return (0);
		if(!create(philo))
			return (0);
		trackker(philo);
		while (++i < philo->gp->nb_philo)
		{
			pthread_mutex_destroy(&philo[i].fork);
			pthread_mutex_destroy(&philo[i].print);
		}
		free(philo);
	}
	else
		return (printf("Error : Arguments\n"));
}