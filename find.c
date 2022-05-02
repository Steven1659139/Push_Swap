#include "Push_swap.h"

t_dlist *find_min(t_package_deal *container, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *min;


    if (stack == 'A' && container->stack_a_head)
    {
        end = container->stack_a_head;
        ref = container->stack_a_head->next;
        min = container->stack_a_head;
    }
    else if (stack == 'B' && container->stack_b_head)
    {
        end = container->stack_b_head;
        ref = container->stack_b_head->next;
        min = container->stack_b_head;
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

t_dlist *find_max(t_package_deal *container, char stack)
{
    t_dlist *end;
    t_dlist *ref;
    t_dlist *max;


    if (stack == 'A' && container->stack_a_head)
    {
        end = container->stack_a_head;
        ref = container->stack_a_head->next;
        max = container->stack_a_head;
    }
    else if (stack == 'B' && container->stack_b_head)
    {
        end = container->stack_b_head;
        ref = container->stack_b_head->next;
        max = container->stack_b_head;
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

t_dlist *find_node(t_package_deal *container, int min, int max, char stack)
{
    t_dlist *end;
    t_dlist *node;

    if (stack == 'A')
    {
        end = container->stack_a_head;
        node = container->stack_a_head;
    }
    else
    {
        end = container->stack_b_head;
        node = container->stack_b_head;
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

t_dlist *find_node_bottom(t_package_deal *container, int min, int max, char stack)
{
    int i;
    t_dlist *end;
    t_dlist *node;

    i = 1;
    if (stack == 'A')
    {
        end = container->stack_a_head;
        node = container->stack_a_head;
    }
    else
    {
        end = container->stack_b_head;
        node = container->stack_b_head;
    }
    
    while (node->prev != end)
    {
        if (node->index >= min && node->index <= max)
            return (node);
        node = node->prev;
    }
    return (NULL);
}
