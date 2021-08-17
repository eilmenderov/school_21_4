/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:22 by vleida            #+#    #+#             */
/*   Updated: 2021/08/17 11:12:11 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo.h"

static void	ft_pool_philo(t_table *table)
{
	int	i;

	if (table->error_fl)
		return ;
	i = 0;
	while (i < table->size)
	{
		table->philo_all[i].num = i + 1;
		table->philo_all[i].state = 0;
		table->philo_all[i].nb_eat = 0;
		table->philo_all[i].t_lmeal = 0;
		table->philo_all[i].start_eat = 0;
		table->philo_all[i].l_fork = &table->forks[i];
		table->philo_all[i].r_fork = &table->forks[i + 1];
		table->philo_all[i].table = table;
		i++;
	}
	i--;
	table->philo_all[i].r_fork = &table->forks[0];
}

static void	ft_create(t_table *table)
{
	pthread_mutex_t	*tmp;
	t_philo			*philos;

	tmp = malloc(sizeof(pthread_mutex_t) * (table->size + 2));
	if (!tmp)
	{
		table->error_fl--;
		return ;
	}
	philos = malloc(sizeof(t_philo) * table->size);
	if (!philos)
	{
		free(tmp);
		table->error_fl--;
		return ;
	}
	table->print = &tmp[table->size];
	table->finish_fork = &tmp[table->size + 1];
	table->forks = tmp;
	table->philo_all = philos;
}

static void	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size + 2)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			printf("Error: Init mutex error\n");
			table->error_fl--;
			return ;
		}
		i++;
	}
	table->exception = 0;
	if (table->size % 2 && table->t_eat * 3 > table->t_die)
		table->exception = 1;
}

void	ft_init_table(char **av, t_table *table, int ac)
{
	table->error_fl = 0;
	table->size = ft_atoi_m(av[1], table);
	table->t_die = ft_atoi_m(av[2], table);
	table->t_eat = ft_atoi_m(av[3], table);
	table->t_sleep = ft_atoi_m(av[4], table);
	table->must_eat = MX_INT;
	if (ac == 6)
		table->must_eat = ft_atoi_m(av[5], table);
	table->dead = 0;
	table->nb_full = 0;
	table->t_start = 0;
	if (table->error_fl || !table->size || !table->t_die)
	{
		table->error_fl--, printf("Error: invalid input\n");
		return ;
	}
	ft_create(table), ft_pool_philo(table);
	if (table->error_fl)
		printf("Error: Allocation fail\n");
	ft_init_forks(table);
}
