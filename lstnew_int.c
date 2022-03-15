#include "Push_swap.h"

/* modifier nom et replacer dans la libft */

t_dlist	*lstnew_dbl(int content)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = new;
	new -> prev = new;
	return (new);
}
