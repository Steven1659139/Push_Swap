#include "Push_swap.h"

void    reverse_rotate(t_package_deal *container, char stack)
{
        if (stack == 'C')
    {
        if (container->stack_a_head)
            container->stack_a_head = container->stack_a_head->prev;
        if (container->stack_b_head)
            container->stack_b_head = container->stack_b_head->prev;
    }
    else if (stack == 'A' && container->stack_a_head)
        container->stack_a_head = container->stack_a_head->prev;
    else if (stack == 'B' && container->stack_b_head)
        container->stack_b_head = container->stack_b_head->prev;
    
}