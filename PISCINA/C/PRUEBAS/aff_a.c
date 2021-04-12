#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *str = "Hlkjljhjñlkajho";
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		write(1, "a", 1);
		i++;
	}
	write(1, "\n", 1);

	return (0);
}