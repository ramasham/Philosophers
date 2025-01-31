/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:11:25 by rsham             #+#    #+#             */
/*   Updated: 2025/01/31 20:02:25 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    thinking(t_philo *philo)
{
    if(is_dead(philo))
        return 1;
    print("is thinking", philo, philo->id);
    return 0;
}

int    sleeping(t_philo *philo)
{
     if(is_dead(philo))
        return 1;
    print("is sleeping", philo, philo->id);
    ft_usleep(philo ,philo->time_to_sleep);
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
    print("is eating", philo, philo->id);
    philo->last_meal = get_current_time();
    ft_usleep(philo,philo->time_to_eat);
    unlock_forks(philo);
    return 0;
}

void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    if (philo->left_fork == philo->right_fork)
    {
        thinking(philo);
        while (!is_dead(philo))
            ;
        return (NULL);
    }
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
    return (NULL);
}