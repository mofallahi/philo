#include "philo.h"

long long	ft_atoi(char *str)
{
	int	i;
	int	ms;
	int	r;

	ms = 1;
	r = 0;
	i = -1;
	if (!str)
		return (-1);
	while ((str[++i] <= 13 && str[i] >= 9) || str[i] == 32);
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
			ms = -1;
	while (str[++i] >= 48 && str[i] <= 57)
		r = str[i] - 48 + r * 10;
	if (str[i] != 0)
		return (0);
	return (r * ms);
}

unsigned long	ft_time()
{
	struct timeval			t_db;
	unsigned long			x;
	static unsigned long	x_0;

	gettimeofday(&t_db, NULL);
	x = t_db.tv_sec * 1000 - t_db.tv_usec / 1000;
	if (!x_0)
		x_0 = x;
	return (x - x_0);
}

int	ft_right_data(int ac, char **av)
{
	while (--ac)
		if (ft_atoi(av[ac]) <= 0)
			return (1);
	return (0);
}

void	ft_printf(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->print);
	if (philo->alive == 1)
		printf("%ld : %d : %s",ft_time(), philo->id, str);
	pthread_mutex_unlock(&philo->print);
}

int	create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].gp->nb_philo)
		if (pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]))
			return (0);
	return (1);
}