#include "../includes/create_time_stamp.h"
#include "../includes/philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int		cnt = 0;

void	print_action(int philo_no, char *action)
{
	t_timestamp	timestamp;

	timestamp = get_timestamp();
	printf("%02d-%02d-%02d %02d:%02d:%02d:%03d > No.%d %s\n", timestamp.year,
		timestamp.month, timestamp.day, timestamp.hour, timestamp.minute,
		timestamp.second, timestamp.millisecond, philo_no, action);
}

int	is_dead(t_philo *philo)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	if ((now_time.tv_sec * 1000 + now_time.tv_usec / 1000)
		- philo->last_eat_time > philo->time_to_die)
	{
		print_action(philo->id, DEAD);
		return (1);
	}
	return (0);
}

int	is_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->right) != 0)
			return (0);
		print_action(philo->id, FORK);
		if (pthread_mutex_lock(philo->left) != 0)
		{
			pthread_mutex_unlock(philo->right);
			return (0);
		}
	}
	else
	{
		if (pthread_mutex_lock(philo->left) != 0)
			return (0);
		print_action(philo->id, FORK);
		if (pthread_mutex_lock(philo->right) != 0)
		{
			pthread_mutex_unlock(philo->left);
			return (0);
		}
	}
	print_action(philo->id, FORK);
	return (1);
}

void	*routine(void *p)
{
	t_philo			*philo;
	struct timeval	now_time;
	int				count;

	philo = (t_philo *)p;
	count = 0;
	gettimeofday(&now_time, NULL);
	philo->eat_count = 0;
	philo->last_eat_time = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		if (is_dead(philo))
			break ;
		if (!is_take_fork(philo))
			continue ;
		print_action(philo->id, EAT);
		usleep(philo->time_to_eat * MILLI_TO_MICRO);
		philo->eat_count++;
		philo->last_eat_time = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		print_action(philo->id, SLEEP);
		usleep(philo->time_to_sleep * MILLI_TO_MICRO);
		print_action(philo->id, THINK);
		if (philo->eat_count == 10)
		{
			print_action(philo->id, "is full");
			break ;
		}
	}
	return (NULL);
}

#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	pthread_t *counter;
	t_philo *philo;
	pthread_mutex_t *mutex;
	int n;
	int i;
	n = argv[1] ? atoi(argv[1]) : 1;
	counter = (pthread_t *)malloc(sizeof(pthread_t) * n);
	philo = (t_philo *)malloc(sizeof(t_philo) * n);
	i = 0;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	while (i < n)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < n)
	{
		philo[i].id = i;
		philo[i].left = &mutex[i];
		philo[i].right = &mutex[(i + 1) % n];
		philo[i].time_to_die = atoi(argv[2]);
		philo[i].time_to_eat = atoi(argv[3]);
		philo[i].time_to_sleep = atoi(argv[4]);
		pthread_create(&counter[i], NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_join(counter[i], NULL);
		i++;
	}
	i = 0;
	while (i < n)
	{
		int status;
		waitpid(counter[i], &status, 0);
		if (WIFEXITED(status))
			printf("philo %d is dead\n", i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
	free(counter);
}