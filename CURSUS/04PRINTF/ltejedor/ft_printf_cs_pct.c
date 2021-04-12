/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_pct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:58 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/05 16:51:08 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_relleno(int *len, t_flags fl)
{
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

void	print_spec_pct(int *len, t_flags fl)
{
	fl.precision = 1;
	if (fl.minus == 0)
		print_relleno(len, fl);
	ft_putchar_len('%', len);
	if (fl.minus == 1)
	{
		fl.pad_c = ' ';
		print_relleno(len, fl);
	}
}

void	print_spec_c(int *len, t_flags fl, char c)
{
	fl.pad_c = ' ';
	fl.precision = 1;
	if (fl.minus == 0)
		print_relleno(len, fl);
	ft_putchar_len(c, len);
	if (fl.minus == 1)
		print_relleno(len, fl);
}

void	print_spec_s(int *len, t_flags fl, char *s)
{
	if (s == NULL)
		s = "(null)";
	if ((fl.point == 1 && fl.precision > (int)ft_strlen(s)) || fl.point == 0)
		fl.precision = ft_strlen(s);
	if (fl.minus == 0)
		print_relleno(len, fl);
	ft_putcstr_len(s, len, fl.precision);
	if (fl.minus == 1)
	{
		fl.pad_c = ' ';
		print_relleno(len, fl);
	}
}
