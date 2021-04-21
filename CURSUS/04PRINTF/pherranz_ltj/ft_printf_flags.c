/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:37 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 18:51:11 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	print_width(t_printf *st)
{
	if (st->sign == '-')
		st->width--;
	if (st->precision <= (int)st->lenstr)
		st->precision = (int)st->lenstr;
	if (st->pad_c == '0' && st->minus == 1)
		st->pad_c = ' ';
	while (st->width > st->precision)
	{
		st->lenstr += write(1, &st->pad_c, 1);
		st->width--;
	}
}

static void	print_zeros(t_printf *st)
{
	int		j;

	if (st->spe_c == 'p')
		ft_putcstr_len("0x", st, 2);
	if (st->minus == 0 && st->pad_c == '0')
		print_width(st);
	if (st->point == 1)
	{
		j = st->precision;
		while (j-- > (int)st->lenstr)
			st->lenstr += write(1, "0", 1);
	}
}

void	print_flags(t_printf *st)
{
	st->lenstr = ft_strlen(st->a);
	if (st->nu2 == 0 && st->point == 1 && st->precision == 0)
		st->width++;
	if (st->spe_c == 'p')
		st->width -= 2;
	if (st->point == 1)
		st->pad_c = ' ';
	if (st->minus == 0 && st->pad_c == ' ')
		print_width(st);
	if (st->sign == '-')
		st->lenstr += write(1, &st->sign, 1);
	print_zeros(st);
	if (!(st->nu2 == 0 && st->point == 1 && st->precision == 0))
		ft_putcstr_len(st->a, st, ft_strlen(st->a));
	if (st->minus == 1)
		print_width(st);
}
