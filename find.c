#include "Push_swap.h"

t_dlist *find_min(t_package_deal *list, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *min;


    if (stack == 'A')
    {
        end = list->stack_a_head;
        ref = list->stack_a_head->next;
        min = list->stack_a_head;
    }
    else if (stack == 'B' && list->stack_b_head)
    {
        end = list->stack_b_head;
        ref = list->stack_b_head->next;
        min = list->stack_b_head;
    }
    else
        return (NULL);

    while (ref != end)
    {
        if (min->index > ref->index)
            min = ref;
        ref = ref->next;
    }
    return (min);
}

t_dlist *find_max(t_package_deal *list, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *max;


    if (stack == 'A' && list->stack_a_head)
    {
        end = list->stack_a_head;
        ref = list->stack_a_head->next;
        max = list->stack_a_head;
    }
    else if (stack == 'B' && list->stack_b_head)
    {
        end = list->stack_b_head;
        ref = list->stack_b_head->next;
        max = list->stack_b_head;
    }
    else
        return (NULL);
    while (ref != end)
    {
        if (max->index < ref->index)
            max = ref;  
        ref = ref->next;
    }
    return (max);
}

t_dlist *find_node(t_package_deal *list, int min, int max, char stack)
{
    t_dlist *end;
    t_dlist *node;

    if (stack == 'A')
    {
        end = list->stack_a_head;
        node = list->stack_a_head;
    }
    else
    {
        end = list->stack_b_head;
        node = list->stack_b_head;
    }
    if (!node)
        return (NULL);
    while (node->next != end)
    {
        if (node->index >= min && node->index <= max)
            return (node);
        node = node->next;
    }
    if (node->index >= min && node->index <= max)
        return (node);
    return (NULL);
}

t_dlist *find_node_bottom(t_package_deal *list, int min, int max, char stack)
{
    int i;
    t_dlist *end;
    t_dlist *node;

    i = 1;
    list->find_pos = i;
    if (stack == 'A')
    {
        end = list->stack_a_head;
        node = list->stack_a_head;
    }
    else
    {
        end = list->stack_b_head;
        node = list->stack_b_head;
    }
    
    while (node->prev != end)
    {
        if (node->index >= min && node->index <= max)
            return (node);
        node = node->prev;
        list->find_pos = ++i;
    }
    return (NULL);
}

void    find_pos(t_package_deal *container, t_dlist *node, char stack)
{
    int i;
    t_dlist *start;

    if (!node)
        return ;
    if (stack == 'A')
        start = container->stack_a_head;
    else
        start = container->stack_b_head;

    i = 0;
    while (start->next != node)
    {
        start = start->next;
        container->find_pos = ++i;
    }
}