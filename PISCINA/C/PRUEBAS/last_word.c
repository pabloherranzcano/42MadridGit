#include <unistd.h>
//"HOLA TÍO CCÓMO ESTÁAAS   JÑL CABRONASO"
int main(int ac, char **av)
{
	int j = 0;
	if (ac == 2)
	{
		while (av[1][j])
			j++;
		j--;
		while (av[1][j] == ' ' && av[1][j] == '\t')
			j--;
		while (av[1][j] != ' ' && av[1][j] != '\t')
		{
			j--;
		}
		j++;
		while (av[1][j] != ' ' && av[1][j] != '\t' && av[1][j] != )
		{
			write(1, &av[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}