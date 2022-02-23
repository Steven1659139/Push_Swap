#include "Push_swap.h"

/* modifier nom et replacer dans la libft */

t_dlist	*lstlast(t_dlist **first, t_dlist *lst)
{
	t_dlist	*ptr_first;

	ptr_first = *first;
	if (!lst)
		return (0);
	if (lst -> next == NULL)
		return (lst);

	while (lst -> next != ptr_first)
	{
		lst = lst -> next;
	}
	return (lst);
}