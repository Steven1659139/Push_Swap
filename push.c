#include "Push_swap.h"

// void    pa(t_package_deal *container)
// {

// }

void    pb(t_package_deal *container, char stack)
{   
    if (container->size_a > 0)
    {
        if (stack == 'B' )
        {
            if (!container->stack_b_head)
            {
                container->temp = container->stack_a_head->next;
                //printf("temp = %d\n", container->temp->content);
                container->stack_b_head = container->stack_a_head;
                container->stack_a_head->next->prev = container->stack_a_head->prev;
                container->stack_a_head->prev->next = container->stack_a_head->next;
                
                container->stack_b_head->next = container->stack_b_head;
                container->stack_b_head->prev = container->stack_b_head;
                container->stack_a_head = container->temp;
                container->size_a -= 1;
                container->size_b += 1;
                printf("size_a = %d\n", container->size_a);
                printf("size_b = %d\n", container->size_b);
                if (container->size_a == 0)
                    container->stack_a_head = NULL;
            } 
            else
            {
                
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

                container->size_a -= 1;
                container->size_b += 1;
                printf("size_a = %d\n", container->size_a);
                printf("size_b = %d\n", container->size_b);
                if (container->size_a == 0)
                {
                    printf("Stack A head = NULL\n");
                    container->stack_a_head = NULL;
                    printf("Stack A head = NULL\n");
                }
            }

        }
    }
}

void    pa(t_package_deal *container, char stack)
{   
    if (container->size_b > 0)
    {
        if (stack == 'A' )
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
                container->size_b -= 1;
                container->size_a += 1;
                printf("size_a = %d\n", container->size_a);
                printf("size_b = %d\n", container->size_b);
                if (container->size_b == 0)
                    container->stack_b_head = NULL;
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

                container->size_b -= 1;
                container->size_a += 1;
                printf("size_a = %d\n", container->size_a);
                printf("size_b = %d\n", container->size_b);
                if (container->size_b == 0)
                    container->stack_b_head = NULL;
            }
        }
    }
}