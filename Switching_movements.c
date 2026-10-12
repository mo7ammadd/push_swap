/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:21:29 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/12 08:28:08 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stack_a)
{
    t_node  *first;
    t_node  *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second = first;
    *stack_a = second;
    write(1,"sa",3);
}