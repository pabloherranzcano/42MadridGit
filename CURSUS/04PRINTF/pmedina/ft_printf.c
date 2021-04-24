/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:12:10 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/24 15:04:40 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	recorrestr(t_printf *j)
{
	j->lenstr = 0;
	while (*j->str)
	{
		if (*j->str == '%')
		{
			initstruct(j);
			guesstype(j);
			if (*j->str != 'd' && *j->str != 'i' &&
				*j->str != 'c' && *j->str != 's' &&
				*j->str != 'u' && *j->str != 'x' &&
				*j->str != 'X' && *j->str != 'p' &&
				*j->str != '%')
				break ;
		}
		else
			j->lenstr += write(1, j->str, 1);
		j->str++;
	}
}

int		ft_printf(const char *s, ...)
{
	t_printf j;

	j.str = (char *)s;
	va_start(j.args, s);
	recorrestr(&j);
	va_end(j.args);
	return (j.lenstr);
}
