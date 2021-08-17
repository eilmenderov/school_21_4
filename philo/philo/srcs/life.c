/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:01 by vleida            #+#    #+#             */
/*   Updated: 2021/08/17 08:51:45 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo.h"

static int	ft_chek_for_dead(t_philo *philo)
{
	long	time;

	time = ft_time();
	if (time - philo->t_lmeal > philo->table->t_die)
	{
		time = time - philo->start_eat;
		pthread_mutex_lock(philo->table->print);
		if (philo->state == 1 || philo->table->size <= philo->table->nb_full)
			return (1);
		printf("\033[31m%ld ms %d is died\033[0m\n", time, philo->num);
		philo->state = 1;
		return (1);
	}
	return (0);
}

static int	ft_take_forks(t_philo *philo)
{
	if (philo->num % 2)
	{
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		ft_print_action("\033[33m%ld ms %d has taken a fork\033[0m\n", philo);
		if (philo->table->size == 1)
		{
			ft_usleep(philo->table->t_die + 1, philo);
			pthread_mutex_unlock(philo->r_fork);
			return (0);
		}
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		ft_print_action("\033[33m%ld ms %d has taken a fork\033[0m\n", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		ft_print_action("\033[33m%ld ms %d has taken a fork\033[0m\n", philo);
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		ft_print_action("\033[33m%ld ms %d has taken a fork\033[0m\n", philo);
	}
	return (1);
}

static void	ft_eating(t_philo *philo)
{
	if (philo->table->exception && philo->num == philo->table->size
		&& philo->table->size != 1)
		ft_usleep(philo->table->t_die + 1, philo);
	if (ft_take_forks(philo))
	{
		philo->nb_eat++;
		ft_print_action("\033[32m%ld ms %d is eating\033[0m\n", philo);
		ft_usleep(philo->table->t_eat, philo);
		if (pthread_mutex_unlock(philo->r_fork))
			return ;
		if (pthread_mutex_unlock(philo->l_fork))
			return ;
		if (ft_chek_for_dead(philo))
			return ;
		philo->t_lmeal = ft_time();
		if (philo->table->must_eat == philo->nb_eat)
		{
			pthread_mutex_lock(philo->table->finish_fork);
			philo->table->nb_full++;
			pthread_mutex_unlock(philo->table->finish_fork);
		}
	}
}

static void	ft_other_action(t_philo *philo)
{
	int	time;

	if (philo->table->nb_full < philo->table->size)
	{
		ft_print_action("\033[34m%ld ms %d is sleeping\033[0m\n", philo);
		ft_usleep(philo->table->t_sleep, philo);
		if (ft_chek_for_dead(philo))
			return ;
	}
	if (philo->table->nb_full < philo->table->size)
	{
		ft_print_action("\033[35m%ld ms %d is thinking\033[0m\n", philo);
		if (philo->table->t_eat > philo->table->t_sleep)
		{
			time = philo->table->t_eat - philo->table->t_sleep - 1;
			ft_usleep(time, philo);
		}
	}
}

void	*ft_life(void *point)
{
	t_philo	*philo;

	philo = (t_philo *)point;
	philo->t_lmeal = philo->start_eat;
	while (!philo->state && philo->table->nb_full < philo->table->size
		&& !philo->table->error_fl)
	{
		if (!philo->state)
			ft_eating(philo);
		if (!philo->state)
			ft_other_action(philo);
		if (!philo->state)
			usleep(TT_SLEEP);
	}
	usleep(TT_SLEEP * 3);
	return ((void *) NULL);
}
