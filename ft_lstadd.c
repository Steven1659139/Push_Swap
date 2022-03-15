#include "Push_swap.h"

void    lstadd(t_dlist **first, t_dlist *new)
{
    t_dlist *elem1;
    t_dlist *last;
 

    if (!*first)
    {
        *first = new;
        return ;
    }
    elem1 = *first;

    last = elem1->prev;
    new->prev = last;
    new->next = *first;
    last->next = new;
    elem1->prev = new;
}