#include "Push_swap.h"

int check_sort(t_package_deal *container, int nb)
{
    int i;

    i = 1;
    container->temp = container->stack_a_head;
    while (container->temp->next != container->stack_a_head)
    {
        if ((container->temp->content > container->temp->next->content))
            return (0);
        container->temp = container->temp->next;
        i++;
        //printf("index = %d\n", i);
    }
    if (i < nb)
        return (0);
    //printf("Check sort %d OK\n", nb);
    return (1);
}

void    sort3(t_package_deal *container)
{
    int top;
    int mid;
    int bottom;
    while (!check_sort(container, 3))
        {
            top = container->stack_a_head->content;
            mid = container->stack_a_head->next->content;
            bottom = container->stack_a_head->prev->content;

            if (((top > mid) && (top < bottom)) || ((top < mid) && (top < bottom)))
                sa(container);
            else if ((top < mid) && (top > bottom))
                reverse_rotate(container, 'A');
            else if ((top > mid) && (top > bottom))
                rotate(container, 'A');
        }
}

void    sort5(t_package_deal *container)
{
    if (!check_sort(container, container->size_a))
    {
        t_dlist *min;

        while (container->size_a > 3)
        {
            min = find_min(container, 'A');
            on_top(container, min, 'A');
            pb(container);
        }
        sort3(container);
        while (container->size_a < container->size_max)
            pa(container);


    }


}

void    sort100(t_package_deal *container)
{
    int pos1;
    int pos2;
    int chunk;
    int start;

    chunk = container->size_a / 5;
    start = 1;

    //printf("chunk = %d\n", chunk);
    while (container->size_a > 0)
    {
        while (find_node(container, 1, chunk, 'A'))
        {
            container->node1 = find_node(container, start, chunk, 'A');
            pos1 = ft_abs((container->find_pos - (container->size_a / 2)));
            container->node2 = find_node_bottom(container, start, chunk, 'A');
            pos2 = ft_abs((container->find_pos - (container->size_a / 2)));

            if (pos1 > pos2)
            {
                if (min_or_max(container, container->stack_a_head, 'B'))
                {
                    find_pos(container, container->min_b, 'B');
                    on_top(container, container->min_b, 'B');
                }
                find_pos(container, container->node1, 'A');
                on_top(container, container->node1, 'A');
                pb(container);
            }
            else
            {
                find_pos(container, container->node2, 'A');
                on_top(container, container->node2, 'A');
                pb(container);
            }
        }
        start = chunk;
        chunk = chunk + chunk;


    }
    while (container->size_a < container->size_max)
    {
        find_pos(container, container->max_b, 'B');
        on_top(container, container->max_b, 'B');
        pa(container);
        //printf("sort 100\n");





    }
    //ft_lstprint(container->stack_a_head);
    //ft_lstprint(container->stack_b_head);
}

int min_or_max(t_package_deal *container, t_dlist *node, char stack)
{
    t_dlist *max;
    t_dlist *min;

    max = find_max(container, stack);
    min = find_min(container, stack);
    if (!node || !min || !max)
        return (0);
    if (node->index > (max->index))
        return (1);
    if (node->index < (min->index))
        return (1);
    return (0);
}

void    on_top(t_package_deal *container, t_dlist *node, char stack)
{
    if (!node)
        return ;
    int size;

    find_pos(container, node, stack);
    if (stack == 'A')
    {
        size = container->size_a;
        while (container->stack_a_head != node)
        {
            //printf("node = %d", node->content);
            if (container->find_pos > (size / 2))
                reverse_rotate(container, 'A');
            else
                rotate(container, 'A');
        }
    }
    else
    {
        size = container->size_b;
        while (container->stack_b_head != node)
        {
            if (container->find_pos > (size / 2))
                reverse_rotate(container, 'B');
            else
                rotate(container, 'B');
        }
    }

}