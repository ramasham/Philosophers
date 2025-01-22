NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include

SRS = \
		functions/ft_string/ft_isalnum.c			\
		functions/ft_string/ft_isascii.c			\
		functions/ft_string/ft_isalpha.c			\
		functions/ft_string/ft_isdigit.c			\
		functions/ft_string/ft_isprint.c			\
		functions/ft_string/ft_itoa.c				\
		functions/ft_string/ft_strchr.c			\
		functions/ft_string/ft_strdup.c			\
		functions/ft_string/ft_striteri.c			\
		functions/ft_string/ft_strjoin.c			\
		functions/ft_string/ft_strlcat.c			\
		functions/ft_string/ft_strlcpy.c			\
		functions/ft_string/ft_strlen.c	 		\
		functions/ft_string/ft_strmapi.c			\
		functions/ft_string/ft_strncmp.c			\
		functions/ft_string/ft_strcmp.c			\
		functions/ft_string/ft_strnstr.c			\
		functions/ft_string/ft_strrchr.c			\
		functions/ft_string/ft_strtrim.c			\
		functions/ft_string/ft_substr.c			\
		functions/ft_string/ft_tolower.c			\
		functions/ft_string/ft_toupper.c			\
		functions/ft_string/ft_atoi.c				\
		functions/ft_string/ft_strtok.c			\
		functions/ft_string/ft_split.c		

SRS +=	\
		functions/ft_memory/ft_bzero.c			\
		functions/ft_memory/ft_memset.c			\
		functions/ft_memory/ft_memcpy.c			\
		functions/ft_memory/ft_memmove.c			\
		functions/ft_memory/ft_memchr.c			\
		functions/ft_memory/ft_memcmp.c			\
		functions/ft_memory/ft_calloc.c

SRS +=	\
		functions/ft_io/ft_putchar_fd.c				\
		functions/ft_io/ft_putstr_fd.c				\
		functions/ft_io/ft_putendl_fd.c			\
		functions/ft_io/ft_putnbr_fd.c			\

SRS += \
		functions/get_next_line/get_next_line.c		\
		functions/get_next_line/get_next_line_utils.c	\

SRS +=	\
		functions/ft_list/ft_lstadd_back.c		\
		functions/ft_list/ft_lstadd_front.c		\
		functions/ft_list/ft_lstclear.c			\
		functions/ft_list/ft_lstdelone.c			\
		functions/ft_list/ft_lstiter.c			\
		functions/ft_list/ft_lstlast.c				\
		functions/ft_list/ft_lstmap.c				\
		functions/ft_list/ft_lstnew.c				\
		functions/ft_list/ft_lstsize.c				\

SRS += \
	functions/ft_printf/ft_printf.c			\
	functions/ft_printf/ft_print_hex.c			\
	functions/ft_printf/ft_print_ptr.c			\
	functions/ft_printf/ft_additional.c			\
	functions/ft_printf/ft_write.c			\

OBJS = $(SRS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $?

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re