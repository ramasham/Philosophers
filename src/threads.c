/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:04:34 by rsham             #+#    #+#             */
/*   Updated: 2025/01/26 13:33:14 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void    *print_num(void *arg)
{
    int num = *((int*)arg);
    printf("number is : %d\n", num);
    return (NULL);   
}

int main()
{
    pthread_t thread;
    int num = 42;
    int res = pthread_create(&thread, NULL, print_num, &num);

    pthread_join(thread, NULL);
    // sleep(3);
    // usleep(0);
    printf("main thread\n");
    return (0);
}