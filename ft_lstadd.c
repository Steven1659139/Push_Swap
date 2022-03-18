#include "Push_swap.h"

void    lstadd(t_dlist **first, t_dlist *new)
{
    static int  index;
    t_dlist *elem1;
    t_dlist *last;
 
    index++;
    if (!*first || index == 1)
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