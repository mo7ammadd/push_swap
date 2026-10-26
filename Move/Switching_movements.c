/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switching_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:21:29 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 09:31:22 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
	record_op(OP_SA);
}

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack_a = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
	record_op(OP_RA);
}

void	rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*last2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		last2 = last;
		last = last->next;
	}
	last2->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
	record_op(OP_RRA);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	record_op(OP_PB);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	record_op(OP_PA);
}
