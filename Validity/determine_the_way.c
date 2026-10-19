/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_the_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 07:12:26 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/12 11:01:01 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_flag(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--medium") == 0)
			return (2);
		else if (ft_strcmp(argv[i], "--complex") == 0)
			return (3);
		i++;
	}
	return (4);
}

static int	count_nodes(t_node *stack)
{
	int	sz;

	sz = 0;
	while (stack)
	{
		sz++;
		stack = stack->next;
	}
	return (sz);
}

static int	count_mistakes(t_node *stack)
{
	t_node	*r;
	int		mis;

	mis = 0;
	while (stack)
	{
		r = stack->next;
		while (r)*stack_a
		{
			if (stack->value > r->value)
				mis++;
			r = r->next;
		}
		stack = stack->next;
	}
	return (mis);
}

double	compute_disorder(t_node *stack)
{
	int	sz;
	int	total;

	sz = count_nodes(stack);
	total = sz * (sz - 1) / 2;
	if (total == 0)
		return (0.0);
	return ((double)count_mistakes(stack) / total);
}

int	determine_way(char **argv, int argc, t_node *stack)
{
	int		x;
	double	dis;

	x = determine_flag(argv, argc);
	if (x != 4)
		return (x);
	dis = compute_disorder(stack);
	if (dis < 0.2)
		return (1);
	else if (dis < 0.5)
		return (2);
	return (3);
}
