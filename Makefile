NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -g

SRCS = src/philo.c src/checks.c src/init.c src/utils.c src/routine.c src/death.c \
	src/get_time.c src/threads.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re