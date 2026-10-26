/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switching_movements1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 09:29:47 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 09:29:48 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
	record_op(OP_SB);
}

void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack_b = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
	record_op(OP_RB);
}

void	rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*last2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
	{
		last2 = last;
		last = last->next;
	}
	last2->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
	record_op(OP_RRB);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
	record_op(OP_SS);
}
