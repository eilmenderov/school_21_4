/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_philo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:17 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 16:21:22 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_PHILO_H
# define HEAD_PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MX_INT		2147483647
# define MN_INT		-2147483648
# define TT_SLEEP	100

typedef struct s_philo
{
	int				num;
	int				state;
	int				nb_eat;
	long			t_lmeal;
	long			start_eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*finish_fork;
	t_philo			*philo_all;
}			t_table;

/* free_and_time.c */
long	ft_time(void);
void	ft_usleep(int time_ms, t_philo *philo);
void	ft_free_all(t_table *table);

/* init.c */
void	ft_init_table(char **av, t_table *table, int ac);

/* life.c */
void	*ft_life(void *point);

/* philo_utils.c */
int		ft_atoi_m(char	*str, t_table *table);
void	ft_print_action(char *str, t_philo *philo);

#endif
