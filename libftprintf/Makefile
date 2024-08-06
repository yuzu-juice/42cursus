NAME	= libftprintf.a
SRCS	= main.c \
	print_conversions/print_c.c \
	print_conversions/print_s.c \
	print_conversions/print_p.c \
	print_conversions/print_d.c \
	print_conversions/print_i.c \
	print_conversions/print_u.c \
	print_conversions/print_lower_x.c \
	print_conversions/print_upper_x.c \
	print_conversions/print_percent.c \
	utils/ft_putchar.c \
	utils/ft_putstr.c \
	utils/ft_putnbr.c
OBJS	= $(SRCS:.c=.o)
HEADERS	= libftprintf.h
CC	= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)
	@ranlib $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
