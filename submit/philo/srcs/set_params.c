/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 06:25:57 by nyts              #+#    #+#             */
/*   Updated: 2024/10/11 07:13:43 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_params	*set_args_param(int argc, char **argv)
{
	int			i;
	int			j;
	t_params	*params;

	if (argc < 5 || argc > 6)
		exit(printf("Error: Invalid number of arguments\n") * 0 + 1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				exit(printf("Error: Invalid argument\n") * 0 + 1);
			j++;
		}
		i++;
	}
	params = (t_params *)malloc(sizeof(t_params));
	params->philo_num = atoi(argv[1]);
	params->time_to_die = atoi(argv[2]);
	params->time_to_eat = atoi(argv[3]);
	params->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		params->must_eat_count = atoi(argv[5]);
	else
		params->must_eat_count = -1;
}

t_philo	*set_philo_param(t_params params)
{
	t_philo *philo;
	int i;

	philo = (t_philo *)malloc(sizeof(t_philo) * params.philo_num);
	i = 0;
	while (i < params.philo_num)
	{
		philo[i].id = i;
		philo[i].time_to_die = params.time_to_die;
		philo[i].time_to_eat = params.time_to_eat;
		philo[i].time_to_sleep = params.time_to_sleep;
		philo[i].eat_count = 0;
		i++;
	}
	return (philo);
}