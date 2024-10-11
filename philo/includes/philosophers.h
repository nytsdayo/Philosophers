#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "struct.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT "is eating. ))^q^(("
# define FORK "has taken a fork. 3-<"
# define SLEEP "is sleeping. Zzz"
# define THINK "is thinking. O_o"
# define DEAD "is \033[31mdead.\033[m x_x"

# define DEAD_FLAG 1

t_params	*set_args_param(int argc, char **argv);
#endif