#include "Push_swap.h"
/* 
    décale vers le haut tous les éléments de la stack passée en arguments, le premier devient le dernier.
*/



void    rotate(t_package_deal *container, char stack)
{
    if (stack == 'c')
    {
        if (container->stack_a_head)
            container->stack_a_head = container->stack_a_head->next;
        if (container->stack_b_head)
            container->stack_b_head = container->stack_b_head->next;
        container->nb_move += 1;
        ft_putstr_fd("rr\n", 1);
        
    }
    else if (stack == 'a' && container->stack_a_head)
    {
        container->stack_a_head = container->stack_a_head->next;
        container->nb_move += 1;
        ft_putstr_fd("ra\n", 1);

    }
    else if (stack == 'b' && container->stack_b_head)
    {
        container->stack_b_head = container->stack_b_head->next;
        container->nb_move += 1;
        ft_putstr_fd("rb\n", 1);
    }
}




