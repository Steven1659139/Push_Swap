#include "Push_swap.h"
/* 
    décale vers le haut tous les éléments de la stack passée en arguments, le premier devient le dernier.
*/



void    rotate(t_package_deal *container, char stack)
{
    if (stack == 'C')
    {
        if (container->stack_a_head)
            container->stack_a_head = container->stack_a_head->next;
        if (container->stack_b_head)
            container->stack_b_head = container->stack_b_head->next;
    }
    else if (stack == 'A' && container->stack_a_head)
        container->stack_a_head = container->stack_a_head->next;
    else if (stack == 'B' && container->stack_b_head)
        container->stack_b_head = container->stack_b_head->next;
    
}



