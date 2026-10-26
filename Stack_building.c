/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:56:55 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:56:56 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int v)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = v;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	node_add_back(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node;
	}
}

t_node	*build_stack_a(char **split_argv, int argc, int start)
{
	int		i;
	t_node	*stack_a;
	t_node	*new_node;

	stack_a = NULL;
	i = start;
	while (i < argc)
	{
		new_node = create_node(ft_atoi(split_argv[i]));
		if (!new_node)
			return (NULL);
		node_add_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

void	set_index(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	current = stack;
	while (current != NULL)
	{
		count = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}
