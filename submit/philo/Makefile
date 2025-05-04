CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS_DIR = srcs/
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re