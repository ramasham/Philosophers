/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:26:11 by rsham             #+#    #+#             */
/*   Updated: 2025/01/28 19:02:08 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        write(2, "you should enter 5 or 6 arguments\n", 34);
        return (1);
    }

    t_philo     philos[PHILO_MAX];
    t_program   program;

    if (argc == 5 || argc == 6)
    {
        init_program(&program, philos);
        init_args(philos, argv);
        init_program(&program, philos);
        init_forks(philos);
        init_philo(philos, &program);
        create_philo(&program, philos);
        write(2, "h\n", 2);
    }
    return (0);
}
