int        main(void)
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    int i;
    int size;
    
    size = 10;
    
    i = 0;
    while (i < size)
    {
        
        printf("%d, ", tab[i]);
        i++;
    }
    printf("\n");
    
    
    ft_rev_int_tab(tab, 10);
}
