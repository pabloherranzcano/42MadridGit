/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_pct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:31 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 18:55:26 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	print_relleno(t_printf *st)
{
	while (st->width > st->precision)
	{
		st->lenstr += write(1, &st->pad_c, 1);
		st->width--;
	}
}

void	print_spec_pct(t_printf *st)
{
	st->precision = 1;
	if (st->minus == 0)
		print_relleno(st);
	st->lenstr += write(1, "%", 1);
	if (st->minus == 1)
	{
		st->pad_c = ' ';
		print_relleno(st);
	}
}

void	print_spec_c(t_printf *st, char c)
{
	st->pad_c = ' ';
	st->precision = 1;
	if (st->minus == 0)
		print_relleno(st);
	st->lenstr += write(1, &c, 1);
	if (st->minus == 1)
		print_relleno(st);
}

void	print_spec_s(t_printf *st, char *s)
{
	if (s == NULL)
		s = "(null)";
	if ((st->point == 1 && st->precision > (int)ft_strlen(s)) || st->point == 0)
		st->precision = ft_strlen(s);
	if (st->minus == 0)
		print_relleno(st);
	ft_putcstr_len(s, st, st->precision);
	if (st->minus == 1)
	{
		st->pad_c = ' ';
		print_relleno(st);
	}
}
