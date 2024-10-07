#ifndef STRUCT_H
#define STRUCT_H

#include <pthread.h>
#include <time.h>


typedef struct s_timestamp
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int millisecond;
}   t_timestamp;

typedef struct s_philo
{
    int id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    time_t last_eat_time;
    int eat_count;
} t_philo;

#endif