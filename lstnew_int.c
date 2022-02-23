#include "Push_swap.h"


t_list_dbl	*lstnew_dbl(int content)
{
	t_list_dbl	*new;

	new = (t_list_dbl *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = 0;
	new -> prev = 0;
	return (new);
}
