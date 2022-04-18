#include "Push_swap.h"

void    reverse_rotate(t_package_deal *container, char stack)
{
        if (stack == 'C')
    {
        if (container->stack_a_head)
            container->stack_a_head = container->stack_a_head->prev;
        if (container->stack_b_head)
            container->stack_b_head = container->stack_b_head->prev;
        container->nb_move += 1;
        ft_putstr_fd("rrr\n", 1);
        // printf("Stack A\n");
        // ft_lstprint(container->stack_a_head);
        // printf("Stack B\n");
        // ft_lstprint(container->stack_b_head);
    }
    else if (stack == 'A' && container->stack_a_head)
    {
        container->stack_a_head = container->stack_a_head->prev;
        container->nb_move += 1;
        ft_putstr_fd("rra\n", 1);
        // printf("Stack A\n");
        // ft_lstprint(container->stack_a_head);
        // printf("Stack B\n");
        // ft_lstprint(container->stack_b_head);
    }
    else if (stack == 'B' && container->stack_b_head)
    {
        container->stack_b_head = container->stack_b_head->prev;
        container->nb_move += 1;
        ft_putstr_fd("rrb\n", 1);
    //     printf("Stack A\n");
    //     ft_lstprint(container->stack_a_head);
    //     printf("Stack B\n");
    //     ft_lstprint(container->stack_b_head);
    }
    
}