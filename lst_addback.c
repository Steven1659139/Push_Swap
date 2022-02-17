#include "Push_swap.h"


void	lst_addback(t_intlist **alst, t_intlist *new)
{
	t_intlist	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = lstlast(*alst);
	last -> next = new;
}