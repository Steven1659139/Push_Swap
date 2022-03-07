#include "Push_swap.h"

/* modifier nom et replacer dans la libft */

t_dlist	*lstlast(t_dlist *lst)
{
	if (!lst)
		return (0);
	if (lst -> next == NULL)
		return (lst);

	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}