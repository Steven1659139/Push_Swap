#include"Push_swap.h"

void put_move(t_package_deal *container, char *move)
{
    if(*move == 's')
        filter_swap(container, *(++move));
    else if (*move == 'p')
        filter_push(container, *(++move));
    else if (ft_strlen(move) == 2)
        rotate(container, *(++move));
    else
    {
        move++;
        reverse_rotate(container, *(++move));
    }
}

void filter_push(t_package_deal *container, char c)
{
    if (c == 'a')
        pa(container);
    else if (c == 'b')
        pb(container);
}

void    filter_swap(t_package_deal *container, char c)
{
    if (c == 'a')
        sa(container);
    else if (c == 'b')
        sb(container);
    else
        ss(container);
}