/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:58:01 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 14:12:52 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo_bonus.h"

static void	ft_run_philo(t_table *table)
{
	int			i;
	pid_t		cur_pid;
	t_philo		*philo;

	i = 0;
	philo = table->philo;
	table->t_start = ft_time();
	philo->start_eat = table->t_start;
	while (i < table->size)
	{
		philo->num = i + 1;
		cur_pid = fork();
		if (!cur_pid)
		{
			ft_life(philo);
			break ;
		}
		else if (cur_pid == -1)
			printf("Error: fork error\n"), exit(-1);
		else
			table->pid_all[i] = cur_pid;
		i++;
	}
}

static void	ft_check_philos(t_table *table, int dead, char *str)
{
	int	i;
	int	check;

	(void)dead;
	while (table->nb_full < table->size)
	{
		waitpid(-1, &check, 0);
		if (WIFEXITED(check) && WEXITSTATUS(check) == 1)
		{
			table->dead++;
			break ;
		}
		else if (WIFEXITED(check) && WEXITSTATUS(check) == 2)
			table->nb_full++;
	}
	if (table->dead)
	{
		i = 0;
		while (i < table->size)
			kill(table->pid_all[i], SIGKILL), i++;
	}
	if (table->nb_full == table->size && !table->dead)
		sem_close(table->printer), printf(str, table->must_eat);
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
	sem_post(table.printer);
	sem_close(table.printer);
	return (0);
}
