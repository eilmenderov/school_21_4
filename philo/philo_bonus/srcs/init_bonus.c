/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:55 by vleida            #+#    #+#             */
/*   Updated: 2021/08/17 11:12:22 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo_bonus.h"

static void	ft_pool_philo(t_table *table)
{
	int	i;

	if (table->error_fl)
		return ;
	i = 0;
	table->philo->num = i + 1;
	table->philo->fl = 0;
	table->philo->state = 0;
	table->philo->nb_eat = 0;
	table->philo->t_lmeal = 0;
	table->philo->start_eat = 0;
	table->philo->table = table;
	table->exception = 0;
	if (table->size % 2 && table->t_eat * 3 > table->t_die)
		table->exception = 1;
}

static void	ft_create(t_table *table)
{
	pid_t	*tmp;
	t_philo	*philos;

	tmp = malloc(sizeof(pid_t) * (table->size));
	if (!tmp)
	{
		table->error_fl--;
		return ;
	}
	philos = malloc(sizeof(t_philo));
	if (!philos)
	{
		free(tmp);
		table->error_fl--;
		return ;
	}
	table->pid_all = tmp;
	table->philo = philos;
}

static void	ft_init_sema(t_table *table)
{
	sem_unlink("forks"), sem_unlink("printer");
	table->forks = sem_open("forks", O_RDONLY | O_CREAT, 0664, table->size);
	if (table->forks == SEM_FAILED)
	{
		table->error_fl--;
		printf("Error: opening semaphore\n");
		return ;
	}
	table->printer = sem_open("printer", O_RDONLY | O_CREAT, 0664, 1);
	if (table->printer == SEM_FAILED)
	{
		table->error_fl--;
		printf("Error: opening semaphore\n");
		return ;
	}
}

void	ft_init_table(char **av, t_table *table, int ac)
{
	table->error_fl = 0;
	table->nb_full = 0;
	table->dead = 0;
	table->size = ft_atoi_m(av[1], table);
	table->t_die = ft_atoi_m(av[2], table);
	table->t_eat = ft_atoi_m(av[3], table);
	table->t_sleep = ft_atoi_m(av[4], table);
	table->must_eat = MX_INT;
	if (ac == 6)
		table->must_eat = ft_atoi_m(av[5], table);
	table->t_start = 0;
	if (table->error_fl || !table->size || !table->t_die)
	{
		table->error_fl--, printf("Error: invalid input\n");
		return ;
	}
	ft_create(table), ft_pool_philo(table);
	if (table->error_fl)
		printf("Error: Allocation fail\n");
	ft_init_sema(table);
}
