/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:33 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 14:05:06 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo.h"

static void	ft_run_philo(t_table *table)
{
	int			i;
	pthread_t	thread;
	t_philo		*philo;

	i = 0;
	table->t_start = ft_time();
	while (i < table->size)
	{
		philo = &table->philo_all[i];
		philo->start_eat = table->t_start;
		if (pthread_create(&thread, NULL, ft_life, (void *)philo) != 0)
		{
			usleep(TT_SLEEP);
			ft_free_all(table);
			return ;
		}
		pthread_detach(thread);
		i++;
	}
}

static void	ft_check_philos(t_table *table, int dead, char *str)
{
	int	i;

	while (!dead && table->nb_full < table->size)
	{
		i = 0;
		while (i < table->size)
		{
			if (table->philo_all[i].state == 1 || table->dead)
			{
				table->dead = 1;
				dead = 1;
				break ;
			}
			i++;
		}
		usleep(TT_SLEEP);
	}
	if (table->dead)
	{
		i = 0;
		while (i < table->size)
			table->philo_all[i].state = 1, i++;
	}
	if (table->nb_full == table->size && !dead)
		pthread_mutex_lock(table->print), printf(str, table->must_eat);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
	{
		table.error_fl--, printf("Error: invalid input\n");
		return (0);
	}
	ft_init_table(av, &table, ac);
	if (table.error_fl)
		return (0);
	ft_run_philo(&table);
	ft_check_philos(&table, 0, "All philosophers ate %d meal(s)\n");
	usleep(1000000);
	ft_free_all(&table);
	return (0);
}
