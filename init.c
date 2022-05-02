#include "Push_swap.h"

void    set_index(t_package_deal *container)
{   
    t_dlist *ptr_ref;
    t_dlist *ptr_check;
    int     min;
    int     i;

    i = 0;
    ptr_ref = container->stack_a_head;
    while(i < container->size_a)
    {
        ptr_check = ptr_ref->next;
        min = ptr_ref->content;
        container->temp = ptr_ref;
        while(ptr_check != ptr_ref)
        {
            if ((ptr_check->content < min) && !(ptr_check->index))
            {
                min = ptr_check->content;
                container->temp = ptr_check;
            }
            ptr_check = ptr_check->next;
        }
        if (!(container->temp->index))
            container->temp->index = ++i;
        ptr_ref = ptr_ref->next;
    }
}

