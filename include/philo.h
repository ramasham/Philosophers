/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:50 by rsham             #+#    #+#             */
/*   Updated: 2025/02/01 17:10:14 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				num_times_eat;
	int				id;
	int				*dead;
	size_t			start_time;
	size_t			last_meal;
	size_t			died_time;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				num_times_eat;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	forks[PHILO_MAX];
	t_philo			*philo;
}					t_program;

void				lock_forks(t_philo *philo);
void				unlock_forks(t_philo *philo);
void				init_args(t_program *status, char **argv);
void				init_forks(t_program *philo);
void				init_philo(t_philo *philo, t_program *program);
int					thinking(t_philo *philo);
int					sleeping(t_philo *philo);
void				*routine(void *arg);
size_t				get_current_time(void);
int					ft_usleep(t_philo *philo, size_t ms);
int					is_dead(t_philo *philo);
void				destroy_all(t_program *program, pthread_mutex_t *forks);
int					create_philo(t_program *program, pthread_mutex_t *forks);
void				print(char *str, t_philo *philo, int id);
int					valid_arg(char **argv);
int					only_num(char *arg);
int					ft_atoi(const char *str);
void				init_mutex(t_program *program, t_philo *philo);
void				death_msg(t_philo *philo);

#endif