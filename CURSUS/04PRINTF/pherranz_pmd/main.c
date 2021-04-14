#include "libftprintf.h"

int	main(void)
{
	char z = 'd';
	int x = ft_printf("x = Querido amigo\n");
	int y = printf("y = Querido amigo\n");
	printf("--------------\n");
	ft_printf("FT_PRINTF:\n	Char: %.-1c, Número: %*c, String: %s, x: %d\n", z, , 547, "Carapene", x);
	printf("PRINTF:\n 	Char: %.-1c, Número: %*d, String: %s, y: %d\n", z, 28, 547, "Carapene", y);
}
