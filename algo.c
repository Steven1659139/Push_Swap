#include"Push_swap.h"

void algo(t_package_deal *container)
{
    if (container->size_max <= 5)
        sort5(container);
    else
        chunker(container);
    free(container);
}