/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:37:32 by rsham             #+#    #+#             */
/*   Updated: 2025/01/28 18:40:44 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// supervisor 
    //1. check is dead
    //2. check if the philos ate all meals

int philo_dead(t_philo *philo, size_t time_to_die)
{
    pthread_mutex_lock(philo->meal_lock);
    if ((size_t)get_current_time() - philo->least_meal >= time_to_die && philo->eating == 0)
    {
        pthread_mutex_unlock(philo->meal_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->meal_lock);
    return (0);
}

int is_dead(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->num_of_philo)
    {
        if (philo_dead(&philo[i], philo[i].time_to_die))
        {
            printf("philo %d died\n", philo[i].id);
            pthread_mutex_lock(philo->dead_lock);
            *philo->dead = 1;
            pthread_mutex_unlock(philo->dead_lock);
            return (1);
        }
        i++;
    }
    return (0);
}

int dead_indicator(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->dead_lock);
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

void    *monitor(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    while (1)
    {
        if (is_dead(philo) == 1 || are_all_ate(philo) == 1)
            break;
    }
    return (arg);
}