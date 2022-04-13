#include "Push_swap.h"

t_dlist *find_min(t_package_deal *list, char stack)
{
    t_dlist *end;
    t_dlist *ref;

    if (stack == 'A')
    {
        end = list->stack_a_head;
        ref = list->stack_a_head;
    }


    else if (stack == 'B')
    {
        end = list->stack_b_head;
        ref = list->stack_b_head;
    }

    while (ref->next != list->stack_a_head)
    {
        




    }





}