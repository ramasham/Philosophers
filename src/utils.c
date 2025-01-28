/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:49:06 by rsham             #+#    #+#             */
/*   Updated: 2025/01/28 17:51:45 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

size_t   get_current_time(void)
{
    struct timeval  time;
    
    if (gettimeofday(&time, NULL) == -1)
    {
        write(2, "gettimeofday() fallied\n", 23);
        return (-1);
    }
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_usleep(size_t milliseconds)
{
    size_t  start;

    start = get_current_time();
    while((get_current_time() - start) < milliseconds)
        usleep(500);
    return (0);
}