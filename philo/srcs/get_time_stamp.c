#include "../includes/create_time_stamp.h"

long	*get_month_sec(int year)
{
	long	*month_sec;
	int		month;

	month_sec = (long *)malloc(sizeof(long) * 12);
	month = 1;
	while (month <= 12)
	{
		if (month == 2)
			if (year % 4 != 0 || year % 100 == 0)
				month_sec[month - 1] = 28 * DAY_SEC;
			else
				month_sec[month - 1] = 29 * DAY_SEC;
		else if ((month % 2 == 0 && month < 6) || (month % 2 == 1 && month < 9))
			month_sec[month - 1] = 30 * DAY_SEC;
		else
			month_sec[month - 1] = 31 * DAY_SEC;
		month++;
	}
	return (month_sec);
}

long	get_until_last_year_sec(int year)
{
	long	until_last_year_sec;

	until_last_year_sec = 0;
	while (year > 1970)
	{
		if (year % 4 != 0 || year % 100 == 0)
			until_last_year_sec += 365 * DAY_SEC;
		else
			until_last_year_sec += 366 * DAY_SEC;
		year--;
	}
	return (until_last_year_sec);
}

t_timestamp	get_timestamp(void)
{
	struct timeval	now_time;
	t_timestamp		timestamp;
	long			*month_sec;
	int				month;

	gettimeofday(&now_time, NULL);
	timestamp.year = 1970 + now_time.tv_sec / YEAR_SEC;
	month_sec = get_month_sec(timestamp.year);
	now_time.tv_sec -= get_until_last_year_sec(timestamp.year);
	month = 1;
	while (month <= 12 && now_time.tv_sec / month_sec[month - 1] > 0)
	{
		now_time.tv_sec -= month_sec[month - 1];
		month++;
	}
	free(month_sec);
	timestamp.month = month;
	timestamp.day = now_time.tv_sec / DAY_SEC;
	timestamp.hour = now_time.tv_sec % DAY_SEC / HOUR_SEC + TIME_DIFFERENCE;
	timestamp.minute = now_time.tv_sec % HOUR_SEC / MINUTE_SEC;
	timestamp.second = now_time.tv_sec % MINUTE_SEC;
	timestamp.millisecond = now_time.tv_usec / 1000;
	return (timestamp);
}
