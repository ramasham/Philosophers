/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:37:32 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 17:04:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (((size_t)get_current_time()
			- philo->last_meal) > (size_t)philo->time_to_die)
	{
		if (*philo->dead == 0)
		{
			*philo->dead = philo->id;
			philo->died_time = get_current_time();
			usleep(philo->time_to_die * 1000);
            death_msg(philo);
        }
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
    }
    pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void    death_msg(t_philo *philo)
{
    size_t  death_time;

    death_time = philo->died_time - philo->start_time;
    printf( " %lu %d has died\n", death_time, philo->id);
}