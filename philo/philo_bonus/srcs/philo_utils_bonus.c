/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:58:04 by vleida            #+#    #+#             */
/*   Updated: 2021/08/05 14:50:52 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_philo_bonus.h"

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

	sem_wait(philo->table->printer);
	time = ft_time() - philo->start_eat;
	if (!philo->state)
		printf(str, time, philo->num);
	sem_post(philo->table->printer);
}
