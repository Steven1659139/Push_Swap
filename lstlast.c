#include "Push_swap.h"

/* modifier nom et replacer dans la libft */

t_dlist	*lstlast(t_dlist **first, t_dlist *lst)
{
	if (!lst)
		return (0);
	if (lst -> next == *first)
		return (lst);

	while (lst -> next != *first)
	{
		lst = lst -> next;
	}
	return (lst);
}