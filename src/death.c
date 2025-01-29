/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:37:32 by rsham             #+#    #+#             */
/*   Updated: 2025/01/29 17:21:30 by rsham            ###   ########.fr       */
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
        print("died", philo, philo->id);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (dead);
}

int check_death(t_philo *philo)
{
    if (is_dead(philo) == 1 || are_all_ate(philo) == 1)
        return (1);
    return (0);
}

int are_all_ate(t_philo *philo)
{
    int i;
    int ate;

    i = 0;
    ate = 0;
    
    if (philo->num_times_eat == 0)
        return (0);
    while (i < philo->num_of_philo)
    {
        pthread_mutex_lock(philo[i].meal_lock);
        if (philo[i].meals_eaten >= philo[i].num_times_eat)
            ate++;
        pthread_mutex_unlock(philo[i].meal_lock);
        i++;
    }
    if (ate == philo->num_of_philo)
    {
        pthread_mutex_lock(philo->dead_lock);
        *philo->dead = 1;
        pthread_mutex_unlock(philo->dead_lock);
        return (1);
    }
    return (0);
}
