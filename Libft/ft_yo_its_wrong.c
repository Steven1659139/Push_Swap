#include "libft.h"

void    yo_its_wrong(char *str)
{
    ft_putstr_fd(RED, 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit(0);
}