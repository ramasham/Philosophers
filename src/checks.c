/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:02:52 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 15:15:42 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	only_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	valid_arg(char **argv)
{
	int	i;

	i = 2;
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| only_num(argv[1]) == 1)
	{
		write(2, "Invalid philosophers number\n", 29);
		return (1);
	}
	while (i <= 4)
	{
		if (ft_atoi(argv[i]) <= 0 || only_num(argv[i]) == 1)
		{
			write(2, "Enter valid arguments\n", 23);
			return (1);
		}
		i++;
	}
	if (argv[5] && (ft_atoi(argv[5]) < 0 || only_num(argv[5]) == 1))
	{
		write(2, "Invalid number of times each philosopher must eat\n", 50);
		return (1);
	}
	return (0);
}
