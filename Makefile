
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c ft_printf_content.c count_len_nb.c
AR = ar rcs
RM = rm -f

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re