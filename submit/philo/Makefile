CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)


NAME = philo

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ./includes 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $(INCLUDES) -c $<
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re