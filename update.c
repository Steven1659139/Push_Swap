#include "Push_swap.h"

void    update_stack_B(t_package_deal *container)
{
    container->size_a -= 1;
    container->size_b += 1;
    container->nb_move += 1;
    container->min_b = find_min(container, 'B');
    container->max_b = find_max(container, 'B');
    container->min_a = find_min(container, 'A');
    container->max_a = find_max(container, 'A');
    if (container->size_a == 0)
        container->stack_a_head = NULL;
}

void    update_stack_A(t_package_deal *container)
{
    container->size_b -= 1;
    container->size_a += 1;
    container->nb_move += 1;
    container->min_a = find_min(container, 'A');
    container->max_a = find_max(container, 'A');
    container->min_b = find_min(container, 'B');
    container->max_b = find_max(container, 'B');
    if (container->size_b == 0)
        container->stack_b_head = NULL;



}