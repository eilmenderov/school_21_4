/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_time_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:48 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 14:03:08 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo_bonus.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			rez;

	gettimeofday(&tv, NULL);
	rez = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (rez);
}

static void	ft_right_usleep(long ms, long start)
{
	start = start + ms;
	if (ms > 10)
		usleep ((ms - 10) * 1000);
	while (1)
	{
		if (start < ft_time())
			return ;
		usleep(50);
	}
}

void	ft_usleep(int time_ms, t_philo *philo)
{
	long	life_time;
	long	real_time;

	life_time = philo->t_lmeal + philo->table->t_die;
	real_time = ft_time();
	if (real_time + time_ms > life_time)
	{
		life_time = life_time - real_time;
		ft_right_usleep(life_time, real_time);
		if (philo->state == 1)
			return ;
		life_time = ft_time() - philo->start_eat;
		sem_wait(philo->table->printer);
		printf("\033[31m%ld ms %d is died\033[0m\n", life_time, philo->num);
		ft_free_all(philo->table);
		exit(1);
	}
	ft_right_usleep(time_ms, real_time);
}

void	ft_free_all(t_table	*table)
{
	sem_close(table->forks);
	free(table->philo);
	free(table->pid_all);
}
