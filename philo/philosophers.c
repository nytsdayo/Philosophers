#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include "philosophers.h"
#include "struct.h"

int cnt = 0;

long month_calculator(time_t now_time, int year)
{
    int now_month;
    int i;
    long month_sec[12];

    i = 0;
    while(i < 12)
    {
        if (i % 2 == 0)
        {
            if(i == 2)
                if (year % 4 == 0 && year % 100 != 0)
                    month_sec[i] = 29 * YEAR_SEC;
                else
                    month_sec[i] = 28 * YEAR_SEC;
            else if(i < 7)
                    month_sec[i] = 30 * YEAR_SEC;
            else
                month_sec[i] = 31 * YEAR_SEC;
        }
            month_sec[i] = 2592000;
        if (i == 1)
        {
            if (year % 4 == 0 && year % 100 != 0)
                month_sec[i] = 2505600;
            else
                month_sec[i] = 2419200;
        }
        i++;
    }


    while(year > 1970)
    {
        if (year % 4 == 0)
            now_time -= 366 * (long)YEAR_SEC;
        else
            now_time -= 365 * (long)YEAR_SEC;
        year--;
    }
    i = 0;
    while(i < 12 && now_time / month_sec[i] > 0)
    {
        now_time -= month_sec[i];
        i++;
    }
    return (i + 1);
}

int day_calculator(time_t now_time, int year, int month)
{
    int now_month;
    int i;
    int month_sec[12] = {2678400, 2419200, 2678400, 2592000, 2678400, 2592000, 2678400, 2678400, 2592000, 2678400, 2592000, 2678400};

    i = 0;
    while(year > 1970)
    {
        if (year % 4 == 0 && year % 100 != 0)
            now_time -= 31622400;
        else
            now_time -= 31536000;
        year--;
    }
    i = 0;
    while(i < 12 && now_time / month_sec[i] > 0)
    {
        now_time -= month_sec[i];
        i++;
    }
    return (now_time / 86400 + 1);
}

int hour_calculator(time_t now_time)
{
    return (now_time / 3600 % 24);
}

int minute_calculator(time_t now_time)
{
    return (now_time / 60 % 60);
}

int second_calculator(time_t now_time)
{
    return (now_time % 60);
}

t_timestamp get_timestamp()
{
    struct timeval now_time;
    t_timestamp timestamp;
    gettimeofday(&now_time, NULL);
    timestamp.year = 1970 + now_time.tv_sec / 31556926;
    timestamp.month = month_calculator(now_time.tv_sec, timestamp.year);
    timestamp.day = day_calculator(now_time.tv_sec, timestamp.year, timestamp.month);
    timestamp.hour = hour_calculator(now_time.tv_sec + TIME_DIFFERENCE * HOUR_SEC);
    timestamp.minute = minute_calculator(now_time.tv_sec);
    timestamp.second = second_calculator(now_time.tv_sec);
    timestamp.millisecond = now_time.tv_usec / 1000;
    return (timestamp);
}

void print_action(int id, char *action)
{
    t_timestamp timestamp;
    timestamp = get_timestamp();
    printf("%02d-%02d-%02d %02d:%02d:%02d:%03d > No.%d %s\n", timestamp.year, timestamp.month, timestamp.day, timestamp.hour, timestamp.minute, timestamp.second, timestamp.millisecond, id, action);
}

void *routine(void *p)
{
    t_philo *philo = (t_philo *)p;
    struct timeval now_time;
    int count = 0;
    gettimeofday(&now_time, NULL);
    philo->eat_count = 0;
    philo->last_eat_time = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
    if(philo->id % 2 == 1)
        usleep(1000);
    while (1)
    {
        gettimeofday(&now_time, NULL);
        printf("now_time: %ld\n", now_time.tv_sec * 1000 + now_time.tv_usec / 1000);
        printf("last_eat_time: %ld\n", philo->last_eat_time);
        if ((now_time.tv_sec * 1000 + now_time.tv_usec / 1000) - philo->last_eat_time > philo->time_to_die)
        {
            print_action(philo->id, DEAD);
            break;
        }
        pthread_mutex_lock(philo->left);
        print_action(philo->id, FORK);
        if (pthread_mutex_lock(philo->right) == 1)
        {
            pthread_mutex_unlock(philo->left);
            continue;
        }
        print_action(philo->id, FORK);
        print_action(philo->id, EAT);
        usleep(philo->time_to_eat * MILLI_TO_MICRO);
        philo->eat_count++;
        philo->last_eat_time = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
        pthread_mutex_unlock(philo->left);
        pthread_mutex_unlock(philo->right);
        print_action(philo->id, SLEEP);
        usleep(philo->time_to_sleep * MILLI_TO_MICRO);
        print_action(philo->id, THINK);
        if(philo->eat_count == 10)
        {
            print_action(philo->id, "is full");
            break;
        }
    }

    return (NULL);
}

# include <stdlib.h>
# include <sys/wait.h>
int main(int argc, char *argv[])
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
    while(i < n)
    {
        pthread_mutex_init(&mutex[i], NULL);
        i++;
    }
    i = 0;
    while(i < n)
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
    while(i < n)
    {

        pthread_join(counter[i], NULL);
        i++;
    }
    i = 0;
    while(i < n)
    {
        int status;
        waitpid(counter[i], &status, 0);
        if (WIFEXITED(status))
            printf("philo %d is dead\n", i);
        i++;
    }
    i = 0;
    while(i < n)
    {
        pthread_mutex_destroy(&mutex[i]);
        i++;
    }
    free(mutex);
    free(counter);
}