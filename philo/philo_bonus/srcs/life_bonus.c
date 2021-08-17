/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:58 by vleida            #+#    #+#             */
/*   Updated: 2021/08/15 13:42:08 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo_bonus.h"

static int	ft_chek_for_dead(t_philo *philo)
{
	long	time;

	time = ft_time();
	if (time - philo->t_lmeal > philo->table->t_die)
	{
		philo->state = 1;
		time = time - philo->start_eat;
		sem_wait(philo->table->printer);
		printf("\033[31m%ld ms %d is died\033[0m\n", time, philo->num);
		ft_free_all(philo->table);
		exit(1);
	}
	return (0);
}

static int	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->table->forks);
	ft_print_action("\033[33m%ld ms %d has taken a fork\033[0m\n", philo);
	if (philo->table->size == 1)
	{
		ft_usleep(philo->table->t_die + 1, philo);
		sem_post(philo->table->forks);
		return (0);
	}
	else
	{
		if (ft_chek_for_dead(philo))
			return (0);
		sem_wait(philo->table->forks);
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
		sem_post(philo->table->forks);
		sem_post(philo->table->forks);
		if (ft_chek_for_dead(philo))
			return ;
		philo->t_lmeal = ft_time();
		if (philo->nb_eat == philo->table->must_eat)
			exit(2);
	}
}

static void	ft_other_action(t_philo *philo)
{
	int	time;

	ft_print_action("\033[34m%ld ms %d is sleeping\033[0m\n", philo);
	ft_usleep(philo->table->t_sleep, philo);
	if (ft_chek_for_dead(philo))
		return ;
	ft_print_action("\033[35m%ld ms %d is thinking\033[0m\n", philo);
	if (philo->table->t_eat > philo->table->t_sleep)
	{
		time = philo->table->t_eat - philo->table->t_sleep - 1;
		ft_usleep(time, philo);
	}
}

void	ft_life(t_philo	*philo)
{
	philo->t_lmeal = philo->start_eat;
	if (philo->num > (philo->table->size / 2) + 1)
		usleep(20000);
	while (!philo->state)
	{
		if (!philo->state)
			ft_eating(philo);
		if (!philo->state)
			ft_other_action(philo);
		if (!philo->state)
			usleep(TT_SLEEP);
	}
}
