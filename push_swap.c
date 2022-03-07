/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:25:04 by slavoie           #+#    #+#             */
/*   Updated: 2022/02/14 14:02:53 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

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
			printf("ref_content = %d\ncheck_content = %d\n", ptr_ref->content, ptr_check->content);
			if (ptr_ref->content == ptr_check->content)
				return (0);
			ptr_check = ptr_check->next;
		}
		ptr_ref = ptr_ref->next;

		//printf("ptr_ref = %p\n", ptr_ref);
	}
	return (1);
}

void	ft_lstprint(t_dlist **first)
{
	t_dlist *ptr;

	ptr = *first;
	while(ptr->next != NULL)
	{	
		printf("%d -> ", ptr->content);
		ptr = ptr->next;
	}
	printf("%d -> \n", ptr->content);
	/*while(ptr->prev != *first)
	{
		
		printf("%d -> ", ptr->content);
		ptr = ptr->prev;
	}
	printf("%d -> ", ptr->content);
	ptr = ptr->prev;
	printf("%d -> ", ptr->content);*/
}

t_dlist	*convert(char *input)
{
	char **tab;
	t_dlist *int_list;
	int inter;
	int i;

	i = 0;
	tab = ft_split(input, ' ');
	inter = ft_atoi(tab[i]);
	int_list = lstnew_dbl(inter);
	//i++;

	//printf("%d\n", (int)int_list->next->content);
	//printf("%d\n", (int)int_list->content);
	while (tab[++i] != NULL)
	{
		inter = ft_atoi(tab[i]);
		//printf("%d\n", inter);
		lst_addback(&int_list, lstnew_dbl(inter));
		//i++;
	}
	free(tab);
	//ft_lstprint(&int_list);
	//ra(&int_list);
	if (!twin_checker(&int_list))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	ft_lstprint(&int_list);
	return (int_list);
}

t_dlist *convert_sep(char **input)
{
	int i;
	int inter;


	t_dlist *int_list;

	i = 0;

	inter = ft_atoi(input[i]);
	int_list = lstnew_dbl(inter);

	while (input[++i] != NULL)
	{
		inter = ft_atoi(input[i]);
		lst_addback(&int_list, lstnew_dbl(inter));
		//printf("%s\n", input[i]);
	}
	if (!twin_checker(&int_list))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	ft_lstprint(&int_list);
	return (int_list);


}

int	check_input(char **input)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	//printf("string = %s\n", input[j]);
	//j++;
	//printf("string = %s\n", input[j]);
	//printf("char = %c\n", *input[i]);
	while (input[j] != NULL)
	{
		//printf("string = %s\n", input[j]);
		//printf("len = %d\n", (int)ft_strlen(input[j]));
		while (i < ft_strlen(input[j]))
		{
			//printf("char = %c\n", input[j][i]);
			if ((!ft_isdigit(input[j][i]) && !(' ' == input[j][i])))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int main(int argc, char **argv)
{
	argv++;
	//printf("Output_check = %d\n", check_input(argv));
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				//printf("%s", "Arg == 2\n");
				convert(*argv);
			}
			else
			{
				//printf("%s", "Arg + 2\n");
				convert_sep(argv);
			}
		}
	}
	else
		ft_putstr_fd(RED"Error\n", 2);
}