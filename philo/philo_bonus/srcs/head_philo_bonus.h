/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_philo_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:51 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 15:27:52 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_PHILO_BONUS_H
# define HEAD_PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>

# define MX_INT		2147483647
# define MN_INT		-2147483648
# define TT_SLEEP	100

typedef struct s_philo
{
	int				num;
	int				fl;
	int				state;
	int				nb_eat;
	long			t_lmeal;
	long			start_eat;
	struct s_table	*table;
}				t_philo;

typedef struct s_table
{
	int				size;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				nb_full;
	int				dead;
	int				error_fl;
	int				exception;
	long			t_start;
	t_philo			*philo;
	pid_t			*pid_all;
	sem_t			*forks;
	sem_t			*printer;
}			t_table;

/* free_and_time.c */
long	ft_time(void);
void	ft_usleep(int time_ms, t_philo *philo);
void	ft_free_all(t_table	*table);

/* init.c */
void	ft_init_table(char **av, t_table *table, int ac);

/* life.c */
void	ft_life(t_philo	*philo);

/* philo_utils.c */
int		ft_atoi_m(char	*str, t_table *table);
void	ft_print_action(char *str, t_philo *philo);

#endif
