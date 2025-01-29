/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:32:09 by rsham             #+#    #+#             */
/*   Updated: 2025/01/29 18:45:38 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    destroy_all(t_program *program, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&program->write_lock);
    pthread_mutex_destroy(&program->meal_lock);
    pthread_mutex_destroy(&program->dead_lock);
    while (i < program->philo->num_of_philo)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    
}

int	create_philo(t_program *program, pthread_mutex_t *forks)
{
	int			i;
	i = 0;

	// printf("   start time is : %zu\n", program->philo->start_time);
	// printf("   current time is : %zu\n", get_current_time());
	while (i < program->num_of_philo)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &routine,
				&program->philo[i]) != 0)
			destroy_all(program, forks);
		i++;
	}
	i = 0;
	while (i < program->num_of_philo)
	{
		if (pthread_join(program->philo[i].thread, NULL) != 0)
			destroy_all(program, forks);
		i++;
	}
	return (0);
}
