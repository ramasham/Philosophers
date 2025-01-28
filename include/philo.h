/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:50 by rsham             #+#    #+#             */
/*   Updated: 2025/01/28 19:00:07 by rsham            ###   ########.fr       */
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
    int             num_times_eat;
    int             id;
    int             eating;
    int             meals_eaten;
    size_t       start_time;
    size_t       least_meal;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int                *dead;
    pthread_mutex_t                 *write_lock;
    pthread_mutex_t                 *meal_lock;
    pthread_mutex_t         *dead_lock;
    pthread_mutex_t     forks[PHILO_MAX];
    
} t_philo;

typedef struct s_program
{
    int             dead_flag;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
    t_philo *philo;
} t_program;

void    init_args(t_philo *status, char **argv);
void    init_forks(t_philo *philo);
void    init_philo(t_philo *philo, t_program *program);
void    init_program(t_program *program, t_philo *philos);
void    thinking(t_philo *philo);
void    sleeping(t_philo *philo);
void    *routine(void *arg);
size_t  get_current_time(void);
int ft_usleep(size_t milliseconds);
int philo_dead(t_philo *philo, size_t time_to_die);
int is_dead(t_philo *philo);
int dead_indicator(t_philo *philo);
int are_all_ate(t_philo *philo);
void    *monitor(void *arg);
void    destroy_all(t_program *program, pthread_mutex_t *forks);
int	create_philo(t_program *program, pthread_mutex_t *forks);







