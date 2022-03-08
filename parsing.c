#include "Push_swap.h"

int	int_checker(long long nb)
{
	//printf("nb = %lld\n", nb);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int twin_checker(t_dlist **lst)
{
	t_dlist *ptr_ref;
	t_dlist *ptr_check;

	ptr_ref = *lst;
//	printf("ptr_ref = %p\n", ptr_ref);

	while(ptr_ref != NULL)
	{
		ptr_check = ptr_ref->next;
			//printf("ref_content = %d\n check_content = %d\n", ptr_ref->content, ptr_check->content);
			//printf("ptr_check = %p\n", ptr_check);
		while(ptr_check != NULL)
		{
			//printf("ref_content = %d\ncheck_content = %d\n", ptr_ref->content, ptr_check->content);
			if (ptr_ref->content == ptr_check->content)
				return (0);
			ptr_check = ptr_check->next;
		}
		ptr_ref = ptr_ref->next;

		//printf("ptr_ref = %p\n", ptr_ref);
	}
	return (1);
}

int	check_input(char **input)
{
	int i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (input[j] != NULL)
	{
		while (i < ft_strlen(input[j]))
		{
			if ((!ft_isdigit(input[j][i]) && !(' ' == input[j][i]) && !(input[j][i] == '-')))
				return (0);
			if (ft_isdigit(input[j][i]))	
				nb++;
			i++;
		}
		j++;
		i = 0;
	}
	if (nb < 1)
		return (0);
	return (1);
}