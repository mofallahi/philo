#include "philo.h"

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
		philo[i].alive = 1;
		philo[i].nb_eat = 0;
		philo[i].last_meal = 0;
		if (pthread_mutex_init(&philo[i].fork, NULL) || pthread_mutex_init(&philo[i].print, NULL))
			return (printf("Mutex error\n"));
		philo[i].next_fork = &philo[(i + 1) % grp->nb_philo].fork;
	}
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if (!ft_time() && !(philo->id % 2))
		usleep(philo->gp->time_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(&philo.)
	}
}