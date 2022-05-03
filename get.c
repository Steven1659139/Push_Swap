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

    if (stack == 'A' && !container->stack_a_head)
        return (0);
    if (stack == 'B' && !container->stack_b_head)
        return (0);

    max = find_max(container, stack)->index;

    return (max);
}

int get_min(t_package_deal *container, char stack)
{
    int min;

    if (stack == 'A' && !container->stack_a_head)
        return (0);
    if (stack == 'B' && !container->stack_b_head)
        return (0);

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

t_dlist *get_next_node(t_package_deal *container, int min)
{
    t_dlist *node1;
    t_dlist *node2;
    static int count;

    count++;

    node1 = find_node(container, min, min + 3, 'B');
    node2 = find_node_bottom(container, min, min + 3, 'B');

    update_position(container);

    if ((!node1 || !node2) || count < 2)
        return (find_max(container, 'B'));

    if (node1->position < node2->position)
        return (node1);
    else
        return (node2);
}