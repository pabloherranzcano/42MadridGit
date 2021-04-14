/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:55:33 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/14 17:48:11 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Función para comprobar el tipo (la letra después del %)
** para saber qué tenmos que imprimir. Vamos derivando
** el flujo a una función u otra dependiendo de qué tipo sea.
*/

void	guesstype(t_printf *j)
{
	if (*j->str == 'd' || *j->str == 'i')
		printint(j, va_arg(j->args, int));
	if (*j->str == 'c')
		printchar(j, va_arg(j->args, int));
	if (*j->str == 's')
		printstring(j, va_arg(j->args, char *));
	if (*j->str == 'u')
		printuns(j, va_arg(j->args, unsigned int));
	if (*j->str == 'x')
		printhx(j, va_arg(j->args, unsigned long));
	if (*j->str == 'X')
		printhexu(j, va_arg(j->args, unsigned long));
	if (*j->str == 'p')
		printdir(j, va_arg(j->args, unsigned long));
	if (*j->str == '%')
		printchar(j, '%');
}

/*
** Función para recorrer el string:
**	- Inciaizamos la variable lenstr (lo que retorna printf).
**	- Recorremos el array
**	- Si no es %, imprimimos el char (sumando 1 a lenstr).
**	- Si es %, inicializamos la estrcuctura y averiguamos de qué
**	  tipo es lo que vamos a imprimir después.
**	- En caso de que el char después de % no coincida con ningún tipo,
**	  avanzamos en la cadena y vuelta a empezar.
*/

void	recorrestr(t_printf *j)
{
	j->lenstr = 0;
	while (*j->str)
	{
		if (*j->str != '%')
			j->lenstr += write(1, j->str, 1);
		else
		{
			initstruct(j);
			guesstype(j);
			if (*j->str != 'd' && *j->str != 'i'
				&& *j->str != 'c' && *j->str != 's'
				&& *j->str != 'u' && *j->str != 'x'
				&& *j->str != 'X' && *j->str != 'p'
				&& *j->str != '%')
				break ;
		}
		j->str++;
	}
}

/*
** Función para iniciar printf:
**	- Iniciamos la MACRO con los argumentos.
**	- Recorremos el array
**	- Finalizamos la MACRO.
**	- Retornamos la longitud del primer argumento (s).
*/

int	ft_printf(const char *s, ...)
{
	t_printf	j;

	j.str = (char *)s;
	va_start(j.args, s);
	recorrestr(&j);
	va_end(j.args);
	return (j.lenstr);
}
