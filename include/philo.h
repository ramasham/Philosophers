/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:50 by rsham             #+#    #+#             */
/*   Updated: 2025/01/22 18:23:23 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILO_H

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_philo
{
    int         num_of_philo;
    int         time_to_die;
    int         time_to_sleep;
    int         time_to_eat;
    int         num_philo_eat;
    int         id;
    pthread_t   *thread;
    pthread_mutex_t *forks;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    
} t_philo;