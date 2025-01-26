/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:11:25 by rsham             #+#    #+#             */
/*   Updated: 2025/01/26 19:14:51 by rsham            ###   ########.fr       */
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
    // pthread_mutex_lock(philo->left_fork);
    printf("philo %d pick up left fork\n", philo->id);
    // pthread_mutex_lock(philo->right_fork);
    printf("philo %d pick up right fork\n", philo->id);
    printf("philo %d is eating now\n", philo->id);
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


