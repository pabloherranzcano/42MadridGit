#include <unistd.h>

int main(int ac, char **av)
{
	int j = 0;
	if (ac == 2)
	{
		while(av[1][j] == ' ' || av[1][j] == '\t')
		{
			if (av[1][j + 1] == '\0')
			{
				break;
			}
			j++;
		}
		while(av[1][j] != ' ' && av[1][j] != '\t')
		{
			write(1, &av[1][j], 1);
			j++;
		}		
	}
	write(1, "\n", 1);
	return (0);
}