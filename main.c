/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:11:55 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/12 10:12:58 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *s)
{
	while (s && s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

static int	small_case(t_node **a, t_node **b)
{
	if (!is_sorted(*a))
		execute_algorithm(1, a, b);
	free_stack(*a);
	free_stack(*b);
	return (1);
}

static int	run(char **split, int new_argc)
{
	t_node	*a;
	t_node	*b;
	int		start;
	int		choice;
	double	dis;

	start = flags_checker(split, new_argc);
	if (start >= new_argc)
		return (1);
	a = build_stack_a(split, new_argc, start);
	if (!a)
		return (0);
	b = NULL;
	set_index(a);
	if (ft_len(a) <= 5 && !is_bench(split, new_argc))
		return (small_case(&a, &b));
	dis = compute_disorder(a);
	choice = determine_way(split, new_argc, a);
	if (!is_sorted(a))
		execute_algorithm(choice, &a, &b);
	if (is_bench(split, new_argc))
		print_bench(dis, choice, determine_flag(split, new_argc) == 4);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**split;
	int		new_argc;

	if (!argc_checker(argc))
		return (0);
	split = split_input(argc, argv, &new_argc);
	if (!split || !number_checker(split, new_argc) || !run(split, new_argc))
	{
		write(2, "Error\n", 6);
		if (split)
			free_split(split, new_argc);
		return (1);
	}
	free_split(split, new_argc);
	return (0);
}