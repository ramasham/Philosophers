/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:26:11 by rsham             #+#    #+#             */
/*   Updated: 2025/01/31 20:08:31 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo     philos[PHILO_MAX];
    t_program   program;

    if (argc == 5 || argc == 6)
    {
        if (valid_arg(argv) == 1)
            return (1);
        init_args(&program, argv);
        init_forks(&program);
        init_philo(philos, &program);
        create_philo(&program, program.forks);
    }
    return (0);
}
