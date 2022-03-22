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
        }
    }
}

void    ss(t_package_deal *container)
{
    sa(container);
    sb(container);
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