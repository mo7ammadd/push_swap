/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:59:18 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/26 09:20:48 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_element(t_node *stack_a)
{
	int	mn;

	mn = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value < mn)
			mn = stack_a->value;
		stack_a = stack_a->next;
	}
	return (mn);
}

static int	find_index(t_node *stack, int mn)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == mn)
			break ;
		index++;
		stack = stack->next;
	}
	return (index);
}

void	move_to_first(t_node **stack_a, int mn)
{
	int	index;
	int	len;

	index = find_index(*stack_a, mn);
	len = ft_len(*stack_a);
	while ((*stack_a)->value != mn)
	{
		if (index > len / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	sort_simple(t_node **stack_a, t_node **stack_b)
{
	int	mn;

	while (*stack_a)
	{
		mn = min_element(*stack_a);
		move_to_first(stack_a, mn);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
