#include "libftprintf.h"

int	main(void)
{
	char z = 'd';
	int x = ft_printf("x = Querido amigo\n");
	int y = printf("y = Querido amigo\n");
	printf("--------------\n");
	ft_printf("FT_PRINTF:\n	Char: %030c, Número: %030d, String: %s, x: %d\n", z, 28547, "Carapene", x);
	printf("PRINTF:\n 	Char: %030c, Número: %030d, String: %s, y: %d\n", z, 28547, "Carapene", y);
}
