/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:37:32 by rsham             #+#    #+#             */
/*   Updated: 2025/01/31 20:26:58 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philo *philo)
{
    int dead;

    dead = 0;
    pthread_mutex_lock(philo->dead_lock);
    if (((size_t)get_current_time() - philo->last_meal) > (size_t)philo->time_to_die)
    {
        dead = 1;
        *philo->dead = 1;
        print("died", philo, philo->id);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (dead);
}
