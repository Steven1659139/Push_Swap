#include "Push_swap.h"

int check_sort(t_package_deal *container)
{
    container->temp = container->stack_a_head;
    while (container->temp->next != container->stack_a_head)
    {
        if ((container->temp->content > container->temp->next->content))
            return (0);
        container->temp = container->temp->next;
    }
    return (1);
}

void    sort3(t_package_deal *container)
{
    int top;
    int mid;
    int bottom;
    while (!check_sort(container))
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
    if (!check_sort(container))
    {
        while (container->size_a > 3)
            pb(container);
        sort3(container);
        while(!check_sort(container))
        {
            if (container->stack_b_head->content > container->stack_a_head->content)
                rotate(container, 'A');
            if (container->stack_b_head->content < container->stack_a_head->content)
                pa(container);
            if (container->size_a == 5)
            {
                while (!check_sort(container))
                {
                    if (container->stack_b_head->content < container->stack_a_head->content)
                        pa(container);
                    rotate(container, 'A');
                }
            }
        }
    }
}