#include "push_swap.h"

int	ft_max(t_node *stack_b)
{
	int	max;
	int	pos;
	int	max_pos;

	max = stack_b->index;
	stack_b = stack_b->next;
	pos = 1;
	max_pos = 0;
	while (stack_b)
	{
		if (stack_b->index > max)
		{
			max = stack_b->index;
			max_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (max_pos);
}

int	ft_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
int	ft_sqrt(int number)
{
	int i;

	if (number <= 0)
		return (0);
	i = 1;
	while (i * i < number)
		i++;
	return (i);
}