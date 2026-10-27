NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I .
SRCS	= main.c free.c ft_Execution.c bench/ft_bench.c bench/bench_print.c \
		bench/bench_utils.c Stack_building.c \
		Validity/utils.c Validity/duplicates.c Validity/split_words.c \
		Validity/split_input.c Validity/checkers.c \
		Validity/determine_the_way.c \
		Move/Switching_movements.c Move/Switching_movements1.c \
		Move/Switching_movements2.c Move/helper.c \
		algorithm/simple.c algorithm/medium.c algorithm/complex.c \
		algorithm/helper_algo.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re