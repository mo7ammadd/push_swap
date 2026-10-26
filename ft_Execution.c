/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:57:07 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:57:09 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_algorithm(int choice, t_node **stack_a, t_node **stack_b)
{
	if (choice == 1)
		sort_simple(stack_a, stack_b);
	else if (choice == 2)
		push_to_a(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}
