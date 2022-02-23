#include "Push_swap.h"


void	lst_addback(t_list_dbl **alst, t_list_dbl *new)
{
	t_list_dbl	*last;
	t_list_dbl *first;

	first = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = lstlast(*alst);
	new -> prev = last;
	last -> next = new;
	//new ->next = *alst;
	//first->prev = new;	
}