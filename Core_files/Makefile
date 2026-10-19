NAME = push_swap
LIBNAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = utils.c duplicates.c split_words.c split_input.c checkers.c \
	Stack_building.c ft_Execution.c Switching_movements.c \
	determine_the_way.c helper.c \
	algorithm/simple.c algorithm/medium.c algorithm/complex.c \
	algorithm/helper_algo.c

OBJS = $(SRCS:.c=.o)
MAIN_OBJ = main.o

all: $(NAME)

$(NAME): $(LIBNAME) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIBNAME) -o $(NAME)

$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(LIBNAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
