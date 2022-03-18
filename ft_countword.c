int ft_countword(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    return (i);
}