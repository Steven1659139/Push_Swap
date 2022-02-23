#include "Push_swap.h"

t_list_dbl	*lstlast(t_list_dbl *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}