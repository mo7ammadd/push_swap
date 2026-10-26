/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:56:13 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:56:15 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_calc(t_node *stack_a)
{
	int	range;
	int	len;

	len = 0;
	while (stack_a)
	{
		len++;
		stack_a = stack_a->next;
	}
	range = (ft_sqrt(len) * 14) / 10;
	return (range);
}

void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	range;
	int	tmp;

	range = range_calc(*stack_a);
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= range)
		{
			tmp = (*stack_a)->index;
			pb(stack_a, stack_b);
			i++;
			range++;
			if (tmp <= i)
			{
				rb(stack_b);
			}
		}
		else
			ra(stack_a);
	}
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	sort_medium(stack_a, stack_b);
	while (*stack_b)
	{
		pos = ft_max(*stack_b);
		if (pos == 0)
			pa(stack_a, stack_b);
		else
		{
			if (pos > (ft_len(*stack_b) / 2))
				rrb(stack_b);
			else
				rb(stack_b);
		}
	}
}
