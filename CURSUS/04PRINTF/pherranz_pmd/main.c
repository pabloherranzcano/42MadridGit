#include "libftprintf.h"

int	main(void)
{
	char z = 'd';
	printf("-------------- START --------------\n");
	int x = ft_printf("x = Querido amigo\n");
	int y = printf("y = Querido amigo\n");

	// LEN PRINTF CON PRECISIÓN
	printf("-------------- LENPRINTF --------------\n");
	ft_printf("%d\n", x);
	printf("%d\n", y);
	
	// CHAR
	printf("-------------- CHAR --------------\n");
	ft_printf("%c\n", z);
	printf("%c\n", z);

	// STRING
	printf("-------------- STRING --------------\n");
	ft_printf("%s\n", "Carapene");
	printf("%s\n", "Carapene");

	// STRING CON PRECISIÓN .3
	printf("-------------- STRING CON PRECISIÓN .3 --------------\n");
	ft_printf("%.3s\n", "Carapene");
	printf("%.3s\n", "Carapene");

	// INT
	printf("-------------- INT --------------\n");
	ft_printf("%.d\n", 24);
	printf("%.d\n", 24);

	printf("-------------- END --------------\n");
}
