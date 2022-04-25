#include "Push_swap.h"

int     in_stack(t_package_deal *container, int min)
{
    int res;

    container->temp = container->stack_b_head;
    res = 0;
    while (container->temp && !res)
    {
        if(container->temp->content >= min)
            res = 1;
        container->temp = container->temp->next;
    }
    return (res);
}

int move_max(t_package_deal *container, int max_index)
{
    int res;

    res = 0;
    if (max_index == 1)
    {
        put_move(container, "pa");
        if (container->size_a > 1 && container->stack_a_head->content > container->stack_a_head->next->content)
            put_move(container, "sa");
        res = 1;
    }
    return (res);
}

void    order_chunk(t_package_deal *container, int min)
{
    int max_index;
    int mid_index;
    int prev;

    prev = 0;

    while (container->size_b && in_stack(container, min))
    {
        max_index = find_max(container, 'B')->content;
        if (!move_max(container, max_index))
        {
            mid_index = container->size_b / 2;
            if (container->size_b % 2 == 0)
                mid_index++;
            if (mid_index >= max_index)
                prev = do_move(container, "rb", max_index - 1, prev);
            else if (mid_index < max_index)
                prev = do_move(container, "rrb", container->size_b - max_index + 1, max_index - 1);
        }
    }
}

void    chunker(t_package_deal *container)
{
    int count;
    int nb_chunk;
    int flag;

    container->chunk_size = size_chunk(container);
    nb_chunk = container->size_max / container->chunk_size;
    if (container->size_max % container->chunk_size)
        nb_chunk++;
    count = 1;
    flag = 0;
    while (count <= nb_chunk / 2 + 1)
    {
        printf("count = %d\n", count);
        flag = move_chunk(container, count, flag);
        count++;
    }
    count = nb_chunk + 1;
    while (count-- > 0)
        order_chunk(container, container->chunk_size * (count - 1));
}
