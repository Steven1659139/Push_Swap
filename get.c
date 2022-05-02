#include "Push_swap.h"

int get_top(t_dlist *stack)
{
    if (!stack)
        return (0);
    return (stack->index);
}

int get_bottom(t_dlist *stack)
{
    return (stack->prev->index);
}

int get_max(t_package_deal *container, char stack)
{
    int max;

    max = find_max(container, stack)->index;

    return (max);
}

int get_min(t_package_deal *container, char stack)
{
    int min;

    min = find_min(container, stack)->index;

    return (min);
}

int get_node(t_dlist *list, int index)
{
    int node;

    while (list->position != index)
        list = list->next;

    node = list->index;

    return (node);



}