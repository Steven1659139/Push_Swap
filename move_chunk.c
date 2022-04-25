#include "Push_swap.h"

int do_move(t_package_deal *container, char *str, int nb, int prev)
{
    int res;
    int top_a;
    int top_b;
    if (container->stack_a_head)
        top_a = container->stack_a_head->content;
    if (container->stack_b_head)
        top_b = container->stack_b_head->content;
    res = 0;
    while (nb > 0)
    {
        if (!res && prev != 0 && 
                (top_b == prev || (container->size_a > 0 && top_a != prev
                    && top_b == prev - 1)))
        {
            filter_push(container, 'a');
            res = 1;
            if (!ft_strncmp(str, "rb", 2))
                nb--;
        }
        else
        {
            put_move(container, str);
            nb--;
        }
    }
    return (res);
}

int check_chunk(int max, int min, t_package_deal *container)
{
    container->temp = container->stack_a_head;
    int res;

    res = 0;
    while (container->temp && !res)
    {
        if(container->temp->content <= max && container->temp->content >= min)
            res = 1;
        container->temp = container->temp->next;
    }
    return (res);
}

int index_chunk(int max, int min, t_package_deal *container)
{
    int res;
    int i;
    int last_content;

    last_content = container->stack_a_head->prev->content;
    i = 1;
    while (i <= container->size_a && (last_content < min || last_content > max))
    {
        printf("chunk_index = %d\n", i);
        i++;
    }
    res = i - 1;
    return (res);
}

int move_chunk(t_package_deal *container, int count, int flag)
{
    int mid;
    int top;
    

    mid = (container->size_max / 2);
    if (container->size_max % 2 != 0)
        mid++;
    container->max_chunk = mid + (count * container->chunk_size);
    container->min_chunk = mid - (count * container->chunk_size);
    while (check_chunk(container->max_chunk, container->min_chunk, container))
    {
        printf("mid = %d\n", mid);
        top = index_chunk(container->max_chunk, container->min_chunk, container);

        do_move(container, "ra", top, 0);
        put_move(container, "pb");
        if (container->stack_a_head->content < mid && flag == 1)
            put_move(container, "rb");
        else if (flag == 0 && container->stack_a_head->content > mid)
            flag = 1;
    }
    return (flag);
}