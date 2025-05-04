#include "struct.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MILLI_TO_MICRO 1000
#define MILLI (1 / 1000)
#define SECOND 1
#define MINUTE_SEC (SECOND * 60)
#define HOUR_SEC (MINUTE_SEC * 60)
#define DAY_SEC (HOUR_SEC * 24)
#define YEAR_SEC (DAY_SEC * 365)
#define TIME_DIFFERENCE -15

t_timestamp	get_timestamp(void);