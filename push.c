#include "Push_swap.h"

void    pb(t_package_deal *container)
{   
    if (container->size_a > 0)
    {
        if (!container->stack_b_head)
        {
            container->temp = container->stack_a_head->next;
            container->stack_b_head = container->stack_a_head;
            container->stack_a_head->next->prev = container->stack_a_head->prev;
            container->stack_a_head->prev->next = container->stack_a_head->next;
            container->stack_b_head->next = container->stack_b_head;
            container->stack_b_head->prev = container->stack_b_head;
            container->stack_a_head = container->temp;
        } 
        else
        {
            container->temp = container->stack_a_head->next;
            container->stack_a_head->prev->next = container->stack_a_head->next;
            container->stack_a_head->next->prev = container->stack_a_head->prev;
            container->stack_a_head->next = container->stack_b_head;
            container->stack_a_head->prev = container->stack_b_head->prev;
            container->stack_b_head->prev->next = container->stack_a_head;
            container->stack_b_head->prev = container->stack_a_head;
            container->stack_b_head = container->stack_a_head;
            container->stack_a_head = container->temp;
        }
        update_stack_B(container);
        ft_putstr_fd("pb\n", 1); 
    }
}

void    pa(t_package_deal *container)
{   
    if (container->size_b > 0)
    {
        if (!container->stack_a_head)
        {
            container->temp = container->stack_b_head->next;
            container->stack_a_head = container->stack_b_head;
            container->stack_b_head->next->prev = container->stack_b_head->prev;
            container->stack_b_head->prev->next = container->stack_b_head->next;
            container->stack_a_head->next = container->stack_a_head;
            container->stack_a_head->prev = container->stack_a_head;
            container->stack_b_head = container->temp;
        }
        else
        {
            container->temp = container->stack_b_head->next;
            container->stack_b_head->prev->next = container->stack_b_head->next;
            container->stack_b_head->next->prev = container->stack_b_head->prev;
            container->stack_b_head->next = container->stack_a_head;
            container->stack_b_head->prev = container->stack_a_head->prev;
            container->stack_a_head->prev->next = container->stack_b_head;
            container->stack_a_head->prev = container->stack_b_head;
            container->stack_a_head = container->stack_b_head;
            container->stack_b_head = container->temp;
            container->temp = container->stack_b_head->next;
        }
        update_stack_A(container);
        ft_putstr_fd("pa\n", 1);
    }
}

