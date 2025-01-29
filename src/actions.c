/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:11:25 by rsham             #+#    #+#             */
/*   Updated: 2025/01/29 19:14:17 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    thinking(t_philo *philo)
{
    // pthread_mutex_lock(philo->write_lock);
    if(is_dead(philo))
        return 1;
    print("is thinking", philo, philo->id);
    // pthread_mutex_unlock(philo->write_lock);
    return 0;
}

int    sleeping(t_philo *philo)
{
    // pthread_mutex_lock(philo->write_lock);
     if(is_dead(philo))
        return 1;
    print("is sleeping", philo, philo->id);
    ft_usleep(philo ,philo->time_to_sleep);
    // pthread_mutex_unlock(philo->write_lock);
    return 0;
}

int    eating(t_philo *philo)
{
    lock_forks(philo);
    if(is_dead(philo))
    {
        unlock_forks(philo);
        return (1);
    }
    // print("has taken a fork", philo, philo->id);
    // pthread_mutex_lock(philo->write_lock);
    print("is eating", philo, philo->id);
    // pthread_mutex_unlock(philo->write_lock);
    philo->last_meal = get_current_time();
    ft_usleep(philo,philo->time_to_eat);
    unlock_forks(philo);
    return 0;
}

void    lock_forks(t_philo *philo)
{
    if (philo->id % 2)
    {
        pthread_mutex_lock(philo->left_fork);
        print("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->right_fork);
        print("has taken a fork", philo, philo->id);
    }
    else
    {
        print("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->right_fork);
        print("has taken a fork", philo, philo->id);
        pthread_mutex_lock(philo->left_fork);
    }
}

void    unlock_forks(t_philo *philo)
{
    if (philo->id % 2)
    {
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
    }
    else
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
    }
}

void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (philo->num_times_eat)
    {
        if(eating(philo))
            break;
        if(sleeping(philo))
            break;
        if(thinking(philo))
            break;
        philo->num_times_eat--;
    }
    return (arg);
}
