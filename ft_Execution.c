/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:00:56 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/12 08:21:06 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_algorithm(int choice, t_node **stack_a)
{
	choice = 1;
	if (choice == 1)
		sort_simple(stack_a);
	else if (choice == 2)
		sort_medium(stack_a);
	else if (choice == 3)
		sort_complex(stack_a);
}
