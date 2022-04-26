#include "Push_swap.h"

void    sa(t_package_deal *container)
{
    if (container->size_a > 0)
    {
        if (container->size_a == 2)
            rotate(container, 'A');
        else
        {
            container->temp = container->stack_a_head->next->next;
            container->stack_a_head->prev->next = container->stack_a_head->next;
            container->stack_a_head->next->prev = container->stack_a_head->prev;
            container->stack_a_head->next->next = container->stack_a_head;
            container->stack_a_head->prev = container->stack_a_head->next;
            container->stack_a_head->next = container->temp;
            container->temp->prev = container->stack_a_head;
            container->stack_a_head = container->stack_a_head->prev;
            container->nb_move += 1;
            update_position(container);
            ft_putstr_fd("sa\n", 1);
            // printf("Stack A\n");
            // ft_lstprint(container->stack_a_head);
            // printf("Stack B\n");
            // ft_lstprint(container->stack_b_head);         
        }
    }
}

void    sb(t_package_deal *container)
{
    if (container->size_b > 0)
    {
        if (container->size_b == 2)
            rotate(container, 'B');
        else
        {
            container->temp = container->stack_b_head->next->next;
            container->stack_b_head->prev->next = container->stack_b_head->next;
            container->stack_b_head->next->prev = container->stack_b_head->prev;
            container->stack_b_head->next->next = container->stack_b_head;
            container->stack_b_head->prev = container->stack_b_head->next;
            container->stack_b_head->next = container->temp;
            container->temp->prev = container->stack_b_head;
            container->stack_b_head = container->stack_b_head->prev;
            container->nb_move += 1;
            update_position(container);
            ft_putstr_fd("sb\n", 1);
            // printf("Stack A\n");
            // ft_lstprint(container->stack_a_head);
            // printf("Stack B\n");
            // ft_lstprint(container->stack_b_head);             
        }
    }
}

void    ss(t_package_deal *container)
{
    sa(container);
    sb(container);
    update_position(container);
    ft_putstr_fd("ss\n", 1);
    // printf("Stack A\n");
    // ft_lstprint(container->stack_a_head);
    // printf("Stack B\n");
    // ft_lstprint(container->stack_b_head); 
    container->nb_move += 1;
}

// {
//     container->temp = container->stack_b_head->next->next;
//     container->stack_b_head->prev->next = container->stack_b_head->next;
//     container->stack_b_head->next->prev = container->stack_b_head->prev;
//     container->stack_b_head->next->next = container->stack_b_head;
//     container->stack_b_head->prev = container->stack_b_head->next;
//     container->stack_b_head->next = container->temp;
//     container->temp->prev = container->stack_b_head;
//     container->stack_b_head = container->stack_b_head->prev;

// }