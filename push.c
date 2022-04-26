#include "Push_swap.h"

// void    pa(t_package_deal *container)
// {

// }

void    pb(t_package_deal *container)
{   
    if (container->size_a > 0)
    {
        if (!container->stack_b_head)
        {
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);
            container->temp = container->stack_a_head->next;
            //printf("temp = %d\n", container->temp->content);
            container->stack_b_head = container->stack_a_head;
            container->stack_a_head->next->prev = container->stack_a_head->prev;
            container->stack_a_head->prev->next = container->stack_a_head->next;
           
            container->stack_b_head->next = container->stack_b_head;
            container->stack_b_head->prev = container->stack_b_head;
            container->stack_a_head = container->temp;
                        
            //printf("Stack A\n");
            //ft_lstprint(container->stack_a_head);
            //printf("Stack B\n");
            //ft_lstprint(container->stack_b_head);
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);

        } 
        else
        {
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);
            container->temp = container->stack_a_head->next;
            //printf("temp = %d\n", container->temp->content);

            container->stack_a_head->prev->next = container->stack_a_head->next;
            container->stack_a_head->next->prev = container->stack_a_head->prev;
            container->stack_a_head->next = container->stack_b_head;
            container->stack_a_head->prev = container->stack_b_head->prev;
            container->stack_b_head->prev->next = container->stack_a_head;
            container->stack_b_head->prev = container->stack_a_head;
            container->stack_b_head = container->stack_a_head;
            container->stack_a_head = container->temp;

            
            //ft_putstr_fd("pb\n", 1);
            // printf("Stack A\n");
            // ft_lstprint(container->stack_a_head);
            // printf("Stack B\n");
            // ft_lstprint(container->stack_b_head);
            
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);
        
        }
        ft_putstr_fd("pb\n", 1);
        update_stack_B(container);
        update_position(container);

    }
}

void    pa(t_package_deal *container)
{   
    // printf("size_a top pa = %d\n", container->size_a);
    // printf("size_b top pa=  %d\n", container->size_b);
    if (container->size_b > 0)
    {
        if (!container->stack_a_head)
        {
            container->temp = container->stack_b_head->next;
            //printf("temp = %d\n", container->temp->content);
            container->stack_a_head = container->stack_b_head;
            container->stack_b_head->next->prev = container->stack_b_head->prev;
            container->stack_b_head->prev->next = container->stack_b_head->next;
            container->stack_a_head->next = container->stack_a_head;
            container->stack_a_head->prev = container->stack_a_head;
            container->stack_b_head = container->temp;

            //printf("Stack A\n");
            //ft_lstprint(container->stack_a_head);
            //printf("Stack B\n");
            //ft_lstprint(container->stack_b_head);
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);

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
            //printf("temp = %d\n", container->temp->content);
            
            
            //printf("Stack A\n");
            //ft_lstprint(container->stack_a_head);
            //printf("Stack B\n");
            //ft_lstprint(container->stack_b_head);            
            // printf("size_a = %d\n", container->size_a);
            // printf("size_b = %d\n", container->size_b);
        }
        update_position(container);
        ft_putstr_fd("pa\n", 1);
        update_stack_A(container);


    }
}

