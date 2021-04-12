#include <stdio.h>
#include <unistd.h>

int letter_counter(char c)
{
	int aux;
	if (c >= 'a' && c <= 'z')
	aux = c - 96;
	else if (c >= 'A' && c <= 'Z')
	aux = c - 64;
	else
		aux = 1;
	return (aux);
}

int main(int argc, char **argv)
{
	(void)argc;
	int loop;
	int i = 0;
	int k = 0;

	while (argv[1][i])
	{
		loop = letter_counter(argv[1][i]);
		while(loop > k)
		{
			write(1, &argv[1][i], 1);
			loop--;
		}
		i++;
	}
	return (0);
}