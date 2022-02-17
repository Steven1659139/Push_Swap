#include "Push_swap.h"

t_intlist	*lstlast(t_intlist *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}