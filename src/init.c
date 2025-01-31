/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:10:43 by rsham             #+#    #+#             */
/*   Updated: 2025/01/31 20:08:25 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_args(t_program *status, char **argv)
{
    status->num_of_philo = ft_atoi(argv[1]);
    status->time_to_die = ft_atoi(argv[2]);
    status->time_to_eat = ft_atoi(argv[3]);
    status->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        status->num_times_eat = ft_atoi(argv[5]);
    else
        status->num_times_eat = -1;
}

void    init_forks(t_program *philo)
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
    program->philo = philo;
    while (i < program->num_of_philo)
    {
        philo[i].num_times_eat = program->num_times_eat;
        philo[i].time_to_sleep = program->time_to_sleep;
        philo[i].time_to_die = program->time_to_die;
        philo[i].time_to_eat = program->time_to_eat;
        philo[i].id = i + 1;
        philo[i].eating = 0;
        philo[i].meals_eaten = 0;
        philo[i].start_time = get_current_time();
        philo[i].last_meal = get_current_time();
        philo[i].left_fork = &program->forks[i];
        philo[i].right_fork = &program->forks[(i + 1) % program->num_of_philo];
        philo[i].dead = &program->dead_flag;
        philo[i].meal_lock = &program->meal_lock;
        philo[i].write_lock = &program->write_lock;
        philo[i].dead_lock = &program->dead_lock;
        i++;
    }
}


