#include "Push_swap.h"

t_dlist *find_min(t_package_deal *list, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *min;
    int     i;

    i = 1;
    list->find_pos = i;

    if (stack == 'A')
    {
        end = list->stack_a_head;
        ref = list->stack_a_head->next;
        min = list->stack_a_head;
    }
    else
    {
        end = list->stack_b_head;
        ref = list->stack_b_head;
        min = list->stack_b_head;
    }

    while (ref != end)
    {
        i++;
        if (min->index > ref->index)
        {
            min = ref;
            list->find_pos = i;
        }
        ref = ref->next;
    }
    return (min);
}

t_dlist *find_max(t_package_deal *list, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *max;
    int     i;

    i = 1;
    list->find_pos = i;

    if (stack == 'A')
    {
        end = list->stack_a_head;
        ref = list->stack_a_head->next;
        max = list->stack_a_head;
    }
    else
    {
        end = list->stack_b_head;
        ref = list->stack_b_head;
        max = list->stack_b_head;
    }

    while (ref != end)
    {
        i++;
        if (max->index < ref->index)
        {
            max = ref;  
            list->find_pos = i;
        }
        ref = ref->next;
    }
    return (max);
}