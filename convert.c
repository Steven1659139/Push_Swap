#include "Push_swap.h"

void    convert(t_package_deal *container, char *argv)
{
	char **tab;
	t_dlist *stack_a;
	long long inter;
	int i;

	i = 0;
	tab = ft_split(argv, ' ');
	while (tab[i])
	{
		inter = ft_atoi(tab[i]);
		
		if (!int_checker(inter))
            yo_its_wrong("Les nombres doivent tenir dans un int.");
		lstadd(&stack_a, lstnew_dbl(inter));
		container->size_a += 1;
		i++;
	}
	free(tab);
	
    if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.");
	
	container->stack_a_head = stack_a;
	container->size_max = container->size_a;

	set_index(container);
}

void    convert_sep(t_package_deal *container, char **argv)
{
	int i;
	long long inter;
	t_dlist *stack_a;

	i = 0;
	inter = 0;
	while (argv[i] != NULL)
	{
		inter = ft_atoi(argv[i]);
		if (!int_checker(inter))
            yo_its_wrong("Les nombres doivent tenir dans un int.");

		lstadd(&stack_a, lstnew_dbl(inter));
		i++;
		container->size_a += 1;
	}

    if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.");

	container->stack_a_head = stack_a;
	container->size_max = container->size_a;

	set_index(container);
	update_position(container);
}