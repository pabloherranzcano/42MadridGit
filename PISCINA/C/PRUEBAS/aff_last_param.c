#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int j = 0;
	if (argc > 1)
		while(argv[argc - 1][j] != '\0')
		{
			write(1, &argv[argc - 1][j], 1);
			j++;
		}
	write(1, "\n", 1);
	return (0);
}