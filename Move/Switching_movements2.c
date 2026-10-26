/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switching_movements2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 09:29:55 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 09:29:56 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	write(1, "rr\n", 3);
	record_op(OP_RR);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	write(1, "rrr\n", 4);
	record_op(OP_RRR);
}
