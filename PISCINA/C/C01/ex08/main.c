

}

int        main(void)
{
    int i;
    int tab[] = {3, 0, 48, 23, 7, 6, 45, 1};
    
    ft_sort_int_tab(tab, 8);
    for(i=0; i<size; i++)
    {
        printf("%d, ", tab[i]);
    }
    
    return (0);
}

