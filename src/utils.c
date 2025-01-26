/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:49:06 by rsham             #+#    #+#             */
/*   Updated: 2025/01/26 19:03:43 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

uint64_t   get_current_time(void)
{
    struct timeval  tv;
    
    if (gettimeofday(&tv, NULL) == -1)
    {
        write(2, "gettimeofday() fallied\n", 23);
        return (-1);
    }
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}