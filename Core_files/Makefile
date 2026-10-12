LIBNAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = utils.c duplicates.c split_words.c split_input.c checkers.c \
	Stack_building.c ft_Execution.c Switching_movements.c \
	determine_the_way.c helper.c

OBJS = $(SRCS:.c=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
