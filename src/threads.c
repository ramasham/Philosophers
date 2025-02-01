/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:32:09 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 16:56:16 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	destroy_all(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philo->num_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	create_philo(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
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
