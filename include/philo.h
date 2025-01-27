/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:50 by rsham             #+#    #+#             */
/*   Updated: 2025/01/27 16:56:47 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILO_H

#define PHILO_MAX 200
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct s_philo
{
    int             num_of_philo;
    int             time_to_die;
    int             time_to_sleep;
    int             time_to_eat;
    int             num_philo_eat;
    int             id;
    int             eating;
    int             meals_eaten;
    uint64_t        start_time;
    uint64_t        least_meal;
    pthread_t       *thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int                *dead;
    pthread_mutex_t                 *write_lock;
    pthread_mutex_t                 *meal_lock;
    pthread_mutex_t     *forks;
    
} t_philo;

typedef struct s_program
{
    int             dead_flag;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    t_philo *philo;
} t_program;

void    init_args(t_philo *status, char **argv);
void    init_forks(t_philo *philo);
void    init_philo(t_philo *philo, t_program *program);
void    init_program(t_program *program, t_philo *philos);
void    create_philos(t_philo *philo);
void    thinking(t_philo *philo);
void    sleeping(t_philo *philo);
void    *routine(void *arg);
uint64_t   get_current_time(void);


