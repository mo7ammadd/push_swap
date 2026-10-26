/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 09:13:31 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 09:13:36 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* utils.c */
int					ft_strcmp(const char *s1, const char *s2);
int					is_valid_int(const char *str);
int					ft_atoi(const char *nptr);
int					argc_checker(int argc);

/* duplicates.c */
int					dublicat_numbers(char **argv, int index, int start);
int					dublicat_flags(char **argv, char *target, int index);

/* split_words.c */
int					word_count(char *str);
char				*word_dup(char *str, int *i);
char				**ft_split(char *str);

/* split_input.c */
char				**split_input(int argc, char **argv, int *new_argc);

/* checkers.c */
int					is_flag(char *s);
int					flags_checker(char **argv, int argc);
int					number_checker(char **argv, int argc);

/* determine_the_way.c */
int					determine_flag(char **argv, int argc);
double				compute_disorder(t_node *stack);
int					determine_way(char **argv, int argc, t_node *stack);

/* stack building */
t_node				*create_node(int v);
void				node_add_back(t_node **stack, t_node *new_node);
t_node				*build_stack_a(char **split_argv, int argc, int start);
void				set_index(t_node *stack);
void				execute_algorithm(int choice, t_node **stack_a,
						t_node **stack_b);

/* algorithm/helper_algo.c */
int					ft_max(t_node *stack_b);
int					ft_len(t_node *stack);
int					ft_sqrt(int number);

/* algorithm/simple.c */
int					min_element(t_node *stack_a);
void				move_to_first(t_node **stack_a, int mn);
void				sort_simple(t_node **stack_a, t_node **stack_b);

/* algorithm/medium.c */
int					range_calc(t_node *stack_a);
void				sort_medium(t_node **stack_a, t_node **stack_b);
void				push_to_a(t_node **stack_a, t_node **stack_b);

/* algorithm/complex.c */
void				sort_complex(t_node **stack_a, t_node **stack_b);

/* operations */
void				reverse_rotate_nodes(t_node **stack);
void				rotate_nodes(t_node **stack);
void				swap_nodes(t_node **stack);
void				sa(t_node **stack_a);
void				ra(t_node **stack_a);
void				rra(t_node **stack_a);
void				sb(t_node **stack_b);
void				rb(t_node **stack_b);
void				rrb(t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}					t_op;

typedef struct s_stats
{
	int				count[OP_COUNT];
	int				total;
}					t_stats;

t_stats				*get_stats(void);
void				record_op(int op);
int					is_bench(char **argv, int argc);
void				print_bench(double dis, int choice, int adaptive);
void				put_str(char *s);
void				put_nbr(int n);
#endif
