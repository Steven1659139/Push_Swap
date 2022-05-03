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
                put_move(container, "rra");
            else if ((top > mid) && (top > bottom))
                put_move(container, "ra");
        }
}

void    sort5(t_package_deal *container)
{
    if (!check_sort(container, container->size_a))
    {
        t_dlist *min;

        while (container->size_a > 3)
        {
            min = find_min(container, 'a');
            on_top(container, min, 'a');
            pb(container);
        }
        sort3(container);
        while (container->size_a < container->size_max)
            pa(container);
    }
}



void    sort100(t_package_deal *container)
{
    int chunk;
    int min_chunk;
    int max_chunk;
    int min;
    t_dlist *node;

    chunk = size_chunk(container);
    min_chunk = (container->size_max / 2) - chunk;
    max_chunk = (container->size_max / 2) + chunk;


    while (container->size_a > 0)
    {
        if (container->stack_a_head->index >= min_chunk && container->stack_a_head->index <= max_chunk)
            put_move(container, "pb");
        if (!(check_chunk(max_chunk, min_chunk, container)))
        {
            min_chunk -= chunk;
            max_chunk += chunk;
        }
        if (get_top(container->stack_b_head) < container->size_max / 2)
            put_move(container, "rb");
        node = find_node(container, min_chunk, max_chunk, 'a');
        on_top(container, node, 'a');
        //put_move(container, "ra");
    }
    while(container->size_b > 0)
    {
        min = get_min(container, 'a');
        //printf("min = %d\n", min);
        //node = get_next_node(container, min);
        node = find_max(container, 'b');
        //printf("node = %d\n", node->index);
        on_top(container, node, 'b');


        put_move(container, "pa");
        if (container->stack_a_head)
        {
            if (container->stack_a_head->index > container->stack_a_head->next->index)
                put_move(container, "sa");
        }
        //put_move(container, "pa");
    }
}



// void    sort500(t_package_deal *container)
// {
//     t_dlist *node1;
//     t_dlist *node2;
//     int pos1;
//     int pos2;
//     int chunk;
//     int start;

//     chunk = 33;
//     start = 1;

//     while (container->size_a > 0)
//     {
//         while (find_node(container, start, chunk, 'a'))
//         {
//             node1 = find_node(container, start, chunk, 'a');
//             pos1 = ft_abs((container->find_pos - (container->size_a / 2)));
//             node2 = find_node_bottom(container, start, chunk, 'a');
//             pos2 = ft_abs((container->find_pos - (container->size_a / 2)));

//             if (pos1 > pos2)
//             {
//                 if (min_or_max(container, container->stack_a_head, 'b'))
//                     on_top(container, container->min_b, 'b');
//                 on_top(container, node1, 'a');
//                 pb(container);
//             }
//             else
//             {
//                 if (min_or_max(container, container->stack_a_head, 'b'))
//                     on_top(container, container->min_b, 'b'); 
//                 on_top(container, node2, 'a');
//                 pb(container);
//             }
//         }
//         start = chunk;
//         chunk = chunk + chunk;


//     }
//     while (container->size_a < container->size_max)
//     {
//         on_top(container, container->max_b, 'b');
//         pa(container);
//         //printf("sort 100\n");

//     }
//     printf("nb_move = %d\n", container->nb_move);
//     //ft_lstprint(container->stack_a_head);
//     //ft_lstprint(container->stack_b_head);
// }



int min_or_max(t_package_deal *container, t_dlist *node, char stack)
{
    t_dlist *max;
    t_dlist *min;

    max = find_max(container, stack);
    min = find_min(container, stack);
    if (!node || !min || !max)
        return (0);
    if ((node->index) > (max->index))
        return (1);
    if (node->index < (min->index))
        return (1);
    return (0);
}

void    on_top(t_package_deal *container, t_dlist *node, char stack)
{
    int size;

    if (!node)
        return ;

    if (stack == 'a')
    {
        size = container->size_a;
        while (container->stack_a_head != node)
        {
            update_position(container);

            if (node->position > (size / 2))
                put_move(container, "rra");
            else
                put_move(container, "ra");
        }
    }
    else
    {
        size = container->size_b;
        while (container->stack_b_head != node)
        {
            update_position(container);
            replace(container);
            if (node->position > (size / 2))
                put_move(container, "rrb");
            else
                put_move(container, "rb");
        }
    }

}

void    replace(t_package_deal *container)
{
    t_dlist *node;

    node = container->stack_a_head;
    
    if (container->stack_a_head)
    {
        if (container->stack_a_head->index > container->stack_a_head->next->index )
            put_move(container, "sa");
    }
    if (container->stack_b_head->index == get_max(container,'b') - 1)
        put_move(container, "pa");



}