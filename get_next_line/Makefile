NAME	= get_next_line
SRCS	= get_next_line.c get_next_line_utils.c 

OBJS	= $(SRCS:.c=.o)
HEADERS	= get_next_line.h
COMPILED_HEADER	= get_next_line.h.gch
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
MACRO	= -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) -I $(HEADERS) 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(MACRO) -c $< -o $@

clean:
	rm -f $(OBJS) $(COMPILED_HEADER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
