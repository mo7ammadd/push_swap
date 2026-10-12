#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
#include <unistd.h>

typedef struct s_node
{
    int             value;
    int             index;
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
void execute_algorithm(int choice, t_node **stack_a);
int	determine_flag(char **argv, int argc);
double	compute_disorder(t_node *stack);
int	determine_way(char **argv, int argc, t_node *stack);
void reverse_rotate_nodes(t_node **stack);
void rotate_nodes(t_node **stack);
void swap_nodes(t_node **stack);
void    sa(t_node **stack_a);
void    ra(t_node **stack_a);
void    rra(t_node **stack_a);
void    pb(t_node **stack_a,t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    sb(t_node **stack_b);
void    rb(t_node **stack_b);
void    rrb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

#endif
