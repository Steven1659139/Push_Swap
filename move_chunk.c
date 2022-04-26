#include "Push_swap.h"

int do_move(t_package_deal *container, char *str, int nb, int prev)
{
    int res;//
  
    res = 0;//
    //printf("before while nb = %d\n", nb);
    while (nb > 0)//
    {
        //printf("do_move");
        if (!res && prev != 0 && //
                (get_top(container->stack_b_head) == prev || (container->size_a > 0 && get_top(container->stack_a_head) != prev
                    && get_top(container->stack_b_head) == prev)))
        {
            put_move(container, "pa");//
            res = 1;//
            if (!ft_strncmp(str, "rb", 2))//
                nb--;//
        }
        else//
        {
            put_move(container, str);//
            nb--;//
        }
    }
    return (res);//
}

int check_chunk(int max, int min, t_package_deal *container)
{
    container->temp = container->stack_a_head;//
    int res;//

    res = 0;//
    while (container->temp && !res)//
    {
       // printf("check_ckunk\n");
        if(container->temp->content <= max && container->temp->content >= min)//
            res = 1;
        container->temp = container->temp->next;
    }
    return (res);
}

int index_chunk(int max, int min, t_package_deal *container)
{
    int res;//
    int i;//

    res = 0;
    i = 1;//
	if (min < 0)//
		min = 0;//

    while (i <= container->size_a && (get_node(container->stack_a_head, i) < min || get_node(container->stack_a_head, i) > max))
    {
        printf("chunk_index = %d\n", i);
        i++;//
    }
    res = i - 1;
    
    return (res);
}

int move_chunk(t_package_deal *container, int count, int flag)
{
    int mid;//
    int top;//
    

    mid = (container->size_max / 2);//
    //if (container->size_max % 2 != 0)
     //   mid++;
    container->max_chunk = mid + (count * container->chunk_size);//
    container->min_chunk = mid - (count * container->chunk_size);//
    while (check_chunk(container->max_chunk, container->min_chunk, container))//
    {
       // printf("mid = %d\n", mid);
        top = index_chunk(container->max_chunk, container->min_chunk, container);//
        //printf("top = %d\n", top);

        do_move(container, "ra", top, 0);//
        put_move(container, "pb");//
        printf("top_b = %d\n", get_top(container->stack_b_head));
        printf("mid = %dflag = %d\n", mid, flag);
        if (get_top(container->stack_b_head) < mid && flag == 1)//
        {
            printf("IN\n");
            put_move(container, "rb");//
        }
        else if (flag == 0 && get_top(container->stack_b_head) > mid)//
            flag = 1;//
    }
    //printf("out move_chunk");
    return (flag);//
}