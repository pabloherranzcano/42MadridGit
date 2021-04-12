#include <stdio.h>

int main()
{
	struct perro
	{
		char	*nombre;
		int		edad;
		float	peso;
	}
	perro1 = {
		"Pepinilla",
		10,
		10.8
	},
	perro2 = {
		"Lola",
		14,
		9.40
	};

	printf("%s tiene %i años y pesa %.2f kgs.\n", perro1.nombre, perro1.edad, perro1.peso);


	printf("%s tiene %i años y pesa %.2f kgs.\n", perro2.nombre, perro2.edad, perro2.peso);

}