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

void    sa(t_node **stack_a)
{
    t_node  *first;
    t_node  *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1,"sa\n",3);
}

void    ra(t_node **stack_a)
{
    t_node  *first;
    t_node  *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    last = *stack_a;
    while(last->next != NULL)
    {
        last = last->next;
    }
    *stack_a = first->next;
    last->next = first;
    first->next = NULL;
    write(1,"ra\n",3);
}

void    rra(t_node **stack_a)
{
    t_node  *last;
    t_node  *last2;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    last = *stack_a;
    while(last->next != NULL)
    {
        last2 = last;
        last = last->next;
    }
    last2->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    write(1, "rra\n", 4);
}

void    pb(t_node **stack_a,t_node **stack_b)
{
    t_node  *tmp;

    if (*stack_a == NULL)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}

void    pa(t_node **stack_a, t_node **stack_b)
{
    t_node  *tmp;
    if (*stack_b == NULL)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}

void    sb(t_node **stack_b)
{
    t_node  *first;
    t_node  *second;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1,"sb\n",3);
}

void    rb(t_node **stack_b)
{
    t_node  *first;
    t_node  *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    last = *stack_b;
    while(last->next != NULL)
    {
        last = last->next;
    }
    *stack_b = first->next;
    last->next = first;
    first->next = NULL;
    write(1,"rb\n",3);
}

void    rrb(t_node **stack_b)
{
    t_node  *last;
    t_node  *last2;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    last = *stack_b;
    while(last->next != NULL)
    {
        last2 = last;
        last = last->next;
    }
    last2->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 4);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    swap_nodes(stack_a);
    swap_nodes(stack_b);
    write(1, "ss\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
    rotate_nodes(stack_a);
    rotate_nodes(stack_b);
    write(1, "rr\n", 3);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate_nodes(stack_a);
    reverse_rotate_nodes(stack_b);
    write(1, "rrr\n", 4);
}