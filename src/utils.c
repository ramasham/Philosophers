/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:49:06 by rsham             #+#    #+#             */
/*   Updated: 2025/01/29 19:04:49 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    print(char *str, t_philo *philo, int id)
{   
    (void)str;
    (void)id;
    size_t time;
    pthread_mutex_lock(philo->write_lock);
    time = get_current_time() - philo->start_time;
    // printf("   current time is : %zu\n", get_current_time());
    // printf("   start time is : %zu\n", philo->start_time);
    // printf("   time is : %zu\n", get_current_time() - philo->start_time);
    printf(" %lu %d %s\n", time, id, str);
    pthread_mutex_unlock(philo->write_lock);
}
