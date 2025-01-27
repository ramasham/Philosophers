/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:11:25 by rsham             #+#    #+#             */
/*   Updated: 2025/01/27 13:29:00 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    thinking(t_philo *philo)
{
    printf("philo %d is thinking\n", philo->id);
}

void    sleeping(t_philo *philo)
{
    printf("philo %d is sleeping\n", philo->id);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf("philo %d pick up left fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("philo %d pick up right fork\n", philo->id);
    philo->eating = 1;
    printf("philo %d is eating now\n", philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->least_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    philo->eating = 0;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}
int is_dead(t_philo *philo)
{
    if (get_current_time() - philo->least_meal >= philo->time_to_die)
        return (pthread_mutex_unlock(philo));
}
void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (1)
    {
        thinking(philo);
        eating(philo);
        sleeping(philo);
    }
}


