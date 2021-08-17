/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:57:29 by vleida            #+#    #+#             */
/*   Updated: 2021/08/09 13:57:55 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo.h"

int	ft_atoi_m(char	*str, t_table *table)
{
	int				neg;
	unsigned long	res;

	neg = 1;
	res = 0;
	while (*str && *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= -MN_INT)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str != 0 || neg < 0 || (res > MX_INT && neg > 0))
		table->error_fl--;
	return ((int)res * neg);
}

void	ft_print_action(char *str, t_philo *philo)
{
	long	time;

	if (pthread_mutex_lock(philo->table->print))
	{
		philo->table->error_fl--;
		return ;
	}
	time = ft_time() - philo->start_eat;
	if (!philo->state && philo->table->size > philo->table->nb_full)
		printf(str, time, philo->num);
	if (pthread_mutex_unlock(philo->table->print))
		philo->table->error_fl--;
}
