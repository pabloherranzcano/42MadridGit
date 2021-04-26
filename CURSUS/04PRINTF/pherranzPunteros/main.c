#include "ft_printf.h"

int main (void)
{
	ft_printf("%.p\n", NULL); 
	printf("%.p\n", NULL); 

	ft_printf("%5.p\n", NULL); 
	printf("%5.p\n", NULL); 

	ft_printf("%2.p\n", NULL); 
	printf("%2.p\n", NULL); 

	ft_printf("%.0p\n", NULL); 
	printf("%.0p\n", NULL); 
}
