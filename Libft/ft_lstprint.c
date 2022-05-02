#include "libft.h"

void	ft_lstprint(t_dlist *first)
{
	t_dlist *ptr;

	ptr = first;
	if (!first)
		return ;
	while(ptr->next != first)
	{	
		printf("%d -> ", ptr->content);
		ptr = ptr->next;
	}
	printf("%d -> \n", ptr->content);
}