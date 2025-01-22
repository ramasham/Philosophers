/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:26:11 by rsham             #+#    #+#             */
/*   Updated: 2025/01/22 19:00:51 by rsham            ###   ########.fr       */
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

    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
    if (!philo->forks)
    {
        write(2, "forks allocation failed!\n", 25);
        return ;
    }
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

void    thinking(t_philo *philo)
{
    ft_printf("philo %d is thinking\n", philo->id);
}

void    init_philo(t_philo *philo)
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
        philo[i].id = i;
        if (pthread_create(&philo->thread[i], NULL, NULL, (void *)&philo[i]) != 0)
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

// void    eating(t_philo *status)
// {
    
// }

// void    routine(t_philo)
// {
    
// }

int main(int argc, char **argv)
{
    t_philo *philo;
    
    if (argc == 5 || argc == 6)
    {
        init_args(philo, argv);
        
    }
}
