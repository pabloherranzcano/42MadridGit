#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(void)
{
	int a = ft_strlen("hola tío cómo estás");
	printf("%d", a);
	return (0);
}