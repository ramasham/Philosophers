/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:11:25 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 16:55:38 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
	print("is thinking", philo, philo->id);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
	print("is sleeping", philo, philo->id);
	ft_usleep(philo, philo->time_to_sleep);
	return (0);
}

int	eating(t_philo *philo)
{
	lock_forks(philo);
	if (is_dead(philo))
	{
		unlock_forks(philo);
		return (1);
	}
    print("has taken a fork", philo, philo->id);
    print("has taken a fork", philo, philo->id);
	print("is eating", philo, philo->id);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo, philo->time_to_eat);
	unlock_forks(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->left_fork == philo->right_fork)
	{
		thinking(philo);
		while (!is_dead(philo))
			;
		return (NULL);
	}
	while (philo->num_times_eat)
	{
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
		philo->num_times_eat--;
	}
	return (NULL);
}
