#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int i;
	int j;

	i = 'a';
	j = 'B';
	while (i <= 'y' && j <= 'Z')
	{
		write(1, &i, 1);
		write(1, &j, 1);
		i += 2;
		j += 2;
	}
	write(1, "\n", 1);
	return (0);
}