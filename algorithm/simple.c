#include "push_swap.h"

int min_element(t_node *stack_a)
{
    int mn;

    mn = stack_a -> value;
    stack_a = stack_a -> next;
    while(stack_a)
    {
        if(stack_a -> value < mn)
        mn = stack_a -> value;
        stack_a = stack_a -> next;
    }
    return (mn);
}
void    move_to_first(t_node **stack_a, int mn)
{
    int index;
    int len;
    int f = 0;
    t_node  *st;
    t_node  *tt;

    len = 0;
    tt = *stack_a;
    while(tt && !f)
    {
        len++;
        tt = tt -> next;
    }
    while ((*stack_a) -> value != mn)
    {
        index = 0;
        st = *stack_a;
        while(st)
        {
            if(st -> value == mn)
            {
                if ((double)(index / len) > 0.5)
                rra(&stack_a);
                else
                ra(&stack_a);
                f = 1;
                break;
            }
            index++;
            st = st -> next;
        }
    }
}
void    simple_sort(t_node **stack_a, t_node **stack_b)
{
    int mn;

    while (*stack_a)
    {
        mn = min_element(*stack_a);
        move_to_first(&stack_a, mn);
        pb(stack_a, stack_b);
    }
    while (*stack_b)
    {
        pa(stack_a, stack_b);
    }
}