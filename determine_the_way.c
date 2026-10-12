/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_the_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 07:12:26 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/12 07:53:51 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_flag(char **argv, int argc)
{
	//this function i will call it after calling (number_checker) function
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--medium") ==0)
			return (2);
		else if (ft_strcmpm(argv[i], "--complex") == 0)
			return (3);
		i++;
	}
	return (4);
}

double	compute_disorder(t_node *stack)
{
	t_node	*c;
	t_node	*r;
	int 	mis;
	int	sz;
	int	total;

	mis = 0;
	sz = 0;
	c = stack;
	while (c)
	{
		sz++;
		c = c -> next;
	}
	total = sz * (sz - 1) / 2;
	if (total == 0)
		return (0.0);
	c = stack;
	while (c)
	{
		r = c -> next;
		while (r)
		{
			if (c -> value > r -> value)
				mis++;
			r = r -> next;
		}
		c = c-> next;
	}
	return ((double)mis / total);
}
int	determine_way(char **argv, int argc, t_node *stack)
{
	int	x;
	double	dis;

	x = determine_flag(argv, argc);
	if (x != 4)
		return (x);
	dis = compute_disorder(stack);
	if (dis < 0.2)
		return (1);
	else if (dis >= 0.2 && dis < 0.5)
		return (2);
	return (3);
}
