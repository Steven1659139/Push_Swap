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
            on_top(container, min);
            pb(container);
        }
        sort3(container);
        while (container->size_a < container->size_max)
            pa(container);


    }


}

void    on_top(t_package_deal *stack, t_dlist *node)
{
    while (stack->stack_a_head != node)
    {
        if (stack->find_pos > (stack->size_a / 2))
            reverse_rotate(stack, 'A');
        else
            rotate(stack, 'A');
    }
}