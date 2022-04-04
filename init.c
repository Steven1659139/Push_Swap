#include "Push_swap.h"

void    set_index(t_package_deal *container)
{
    t_dlist *ptr_ref;
    t_dlist *ptr_check;

    ptr_ref = container->stack_a_head;

    while(ptr_ref->next	!= container->stack_a_head)
    {
        ptr_check = ptr_ref->next;
        while(ptr_check != container->stack_a_head)
        {
            //printf("ref_content = %d\ncheck_content = %d\n", ptr_ref->content, ptr_check->content);
            if (ptr_ref < )
                return (0);
            ptr_check = ptr_check->next;
        }
        ptr_ref = ptr_ref->next;
    }
    return (1);
}