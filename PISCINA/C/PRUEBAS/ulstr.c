#include <unistd.h>

int main(int ac, char **av)
{
	(void)ac;
	int j = 0;
	if (ac == 2)
		while(av[1][j])
		{
			if (av[1][j] >= 65 && av[1][j] <= 90)
				av[1][j] += 32;
			else if (av[1][j] >= 97 && av[1][j] <= 122)
				av[1][j] -= 32;
			write(1, &av[1][j], 1);
			j++;
		}
	write(1, "\n", 1);
	
	return(0);
}