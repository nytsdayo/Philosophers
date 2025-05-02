#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>
# include <time.h>

typedef struct s_timestamp
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				minute;
	int				second;
	int				millisecond;
}					t_timestamp;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	time_t			last_eat_time;
	int				eat_count;
	bool			*finish_flag;
}					t_philo;

typedef struct s_params
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
}					t_params;

#endif