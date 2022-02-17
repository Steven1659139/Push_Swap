#include "Push_swap.h"


t_intlist	*lstnew_int(int content)
{
	t_intlist	*new;

	new = (t_intlist *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = 0;
	return (new);
}
