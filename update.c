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

void    update_position(t_package_deal *container)
{
    int i;
    t_dlist *ref;
    
    i = 1;
    ref = container->stack_a_head;
    while (i <= container->size_a)
    {
        ref->position = i;
        ref = ref->next;
        i++;
    }
    ref = container->stack_b_head;
    i = 1;
    while (i <= container->size_b)
    {
        ref->position = i;
        ref = ref->next;
        i++;
    }

}