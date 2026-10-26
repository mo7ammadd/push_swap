#include "push_swap.h"

int num_of_op(int len)
{
    int op;

    op = 0;
    if(len == 1)
    {
        return (0);
    }
    while (((len - 1) >> op) > 0)
    op++;
    return (op);
}

void    sort_complex(t_node **stack_a, t_node **stack_b)
{
    int len;
    int counter;
    int op;
    int i;

    len = ft_len(*stack_a);
    counter = 0;
    op = num_of_op(len);
    while (counter < op)
    {
        i = 0;
        while (i < len)
        {
            if ((*stack_a)->index & (1 << counter))
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            i++;
        }
        while (*stack_b)
        {
            pa(stack_a, stack_b);
        }
        counter++;
    }
}