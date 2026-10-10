#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

int    ft_strcmp(const char *s1, const char *s2);
int	    is_valid_int(const char *str);
int    ft_atoi(const char *nptr);
int    dublicat_numbers(char **argv, int index, int start);
int    dublicat_flags(char **argv, char *target, int index);
int    flags_checker(char **argv, int argc);
int    number_checker(char **argv, int argc);
int    argc_checker(int argc);
int    word_count(char *str);
char    *word_dup(char *str, int *i);
char    **ft_split(char *str);
char    **split_input(int argc, char **argv, int *new_argc);


t_node  *create_node(int v);
void    node_add_back(t_node **stack, t_node *new_node);
t_node  *build_stack_a(char **split_argv, int argc, int start);
void set_index(t_node *stack);
#endif
