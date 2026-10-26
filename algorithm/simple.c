#include "push_swap.h"

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
void	move_to_first(t_node **stack_a, int mn)
{
	int		index;
	int		len;
	t_node	*tmp;

	len = 0;
	index = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == mn)
			break ;
		index++;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
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
	int mn;

	while (*stack_a)
	{
		mn = min_element(*stack_a);
		move_to_first(stack_a, mn);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}