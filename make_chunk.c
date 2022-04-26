#include "Push_swap.h"

int size_chunk(t_package_deal *container)
{
    container->chunk_size = 0;

    if (container->size_max == 100)
        container->chunk_size = 15;
    else if (container->size_max == 500)
        container->chunk_size = 33;
    else //if (container->chunk_size == 0)
        container->chunk_size = container->size_max / 2;
    //else
        //container->chunk_size = container->size_max / 10;
    return (container->chunk_size);
}

