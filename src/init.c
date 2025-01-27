/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:10:43 by rsham             #+#    #+#             */
/*   Updated: 2025/01/27 16:55:22 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_args(t_philo *status, char **argv)
{
    status->num_of_philo = ft_atoi(argv[1]);
    status->time_to_die = ft_atoi(argv[2]);
    status->time_to_eat = ft_atoi(argv[3]);
    status->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        status->num_philo_eat = ft_atoi(argv[5]);
}

void    init_forks(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->num_of_philo)
    {
        if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
        {
            write(2, "init mutex failed!\n", 19);
            return ;
        }
        i++;
    }
}

void    init_philo(t_philo *philo, t_program *program)
{
    int i;

    i = 0;
    while (i < philo->num_of_philo)
    {
        philo[i].id = i + 1;
        philo[i].eating = 0;
        philo[i].start_time = get_current_time();
        philo[i].least_meal = get_current_time();
        philo[i].left_fork = &philo->forks[i];
        philo[i].right_fork = &philo->forks[(i + 1) % philo->num_of_philo];
        philo[i].dead = &program->dead_flag;
        philo[i].meal_lock = &program->meal_lock;
        philo[i].write_lock = &program->write_lock;
        i++;
    }
}

void    init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philo = philos;
    pthread_mutex_int(program->meal_lock, NULL);
    pthread_mutex_int(program->write_lock, NULL);
}
