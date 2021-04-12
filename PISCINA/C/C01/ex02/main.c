int        main(void)
{
    int x;
    int y;
    
    x = 5;
    y = 9;
    
    printf("El valor de X es %d\nEl valor de Y es %d\n", x, y);
    
    ft_swap(&x, &y);
    
    printf("El valor de X es %d\nEl valor de Y es %d", x, y);
    
    return (0);
}
