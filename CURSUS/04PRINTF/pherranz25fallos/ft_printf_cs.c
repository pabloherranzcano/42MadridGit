/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:31 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 17:30:22 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	print_relleno(t_printf *st)
{
	while (st->width > st->precision)
	{
		st->lenstr += write(1, &st->pad, 1);
		st->width--;
	}
}

void	printchar(t_printf *st, char c)
{
	st->precision = 1;
	if (st->minus == 0)
		print_relleno(st);
	st->lenstr += write(1, &c, 1);
	if (st->minus == 1)
	{
		st->pad = ' ';
		print_relleno(st);
	}
}

void	printstring(t_printf *st, char *s)
{
	if (s == NULL)
		s = "(null)";
	if ((st->point == 1 && st->precision > (int)ft_strlen(s)) || st->point == 0)
		st->precision = ft_strlen(s);
	if (st->minus == 0)
		print_relleno(st);
	ft_putstr_len(s, &st->lenstr, st->precision);
	if (st->minus == 1)
	{
		st->pad = ' ';
		print_relleno(st);
	}
}
