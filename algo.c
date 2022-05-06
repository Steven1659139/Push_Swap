#include"Push_swap.h"

void	algo(t_stacks *container)
{
	if (container->size_max <= 5)
		sort5(container);
	else
		universal_sort(container);
	free(container);
}

void	on_top(t_stacks *container, t_dlist *node, char stack)
{
	int	size;

	if (!node)
		return ;

	if (stack == 'a')
	{
		size = container->size_a;
		while (container->a_head != node)
		{
			update_position(container);
			if (node->position > (size / 2))
				put_move(container, "rra");
			else
				put_move(container, "ra");
		}
	}
	else
	{
		size = container->size_b;
		while (container->b_head != node)
		{
			update_position(container);
			replace(container);
			if (node->position > (size / 2))
				put_move(container, "rrb");
			else
				put_move(container, "rb");
		}
	}
}

void	replace(t_stacks *container)
{
	t_dlist	*node;

	node = container->a_head;
	if (container->a_head)
	{
		if (container->a_head->index > container->a_head->next->index )
			put_move(container, "sa");
	}
	if (container->b_head->index == get_max(container,'b') - 1)
		put_move(container, "pa");
}
