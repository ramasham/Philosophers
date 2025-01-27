/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:32:09 by rsham             #+#    #+#             */
/*   Updated: 2025/01/27 17:23:49 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_philos(t_philo *philo)
{
    int i;

    philo->thread = malloc(sizeof(pthread_t) * philo->num_of_philo);
    if (!philo->thread)
    {
        write(2, "philo allocation failed\n", 24);
        return ;
    }
    i = 0;    
    while(i < philo->num_of_philo)
    {
        if (pthread_create(&philo->thread[i], NULL, routine, (void *)&philo[i]) != 0)
        {
            write(2, "creating thread failed\n", 23);
            return ;
        }
        i++;
    }
    i = 0;
    while (i < philo->num_of_philo)
    {
        pthread_join(philo->thread[i], NULL);
        i++;
    }
}