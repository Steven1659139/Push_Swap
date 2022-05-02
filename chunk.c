#include "Push_swap.h"

int size_chunk(t_package_deal *container)
{
    container->chunk_size = 0;

    if (container->size_max == 100)
        container->chunk_size = 15;
    else if (container->size_max == 500)
        container->chunk_size = 33;
    else
        container->chunk_size = container->size_max / 2;

    return (container->chunk_size);
}

int check_chunk(int max, int min, t_package_deal *container)
{
    container->temp = container->stack_a_head;
    int res;

    res = 0;

    if (!container->temp)
        return (0);
    while (container->temp->next != container->stack_a_head && !res)
    {
        if(container->temp->index <= max && container->temp->index >= min)
            res = 1;
        container->temp = container->temp->next;
    }
    return (res);
}