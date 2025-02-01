/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:47:08 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 11:49:28 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(t_philo *philo, size_t ms)
{
	size_t start;

	(void)philo;
	start = get_current_time();
	while ((get_current_time() - start) < ms)
	{
		if (is_dead(philo))
			break ;
	}
	return (0);
}