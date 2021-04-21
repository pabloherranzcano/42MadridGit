/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:37 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 17:08:44 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	print_width(int *len, t_printf fl)
{
	if (fl.sign == '-')
		fl.width--;
	if (fl.precision <= (int)fl.lenstr)
		fl.precision = (int)fl.lenstr;
	if (fl.pad_c == '0' && fl.minus == 1)
		fl.pad_c = ' ';
	while (fl.width > fl.precision)
	{
		*len += write(1, &fl.pad_c, 1);
		fl.width--;
	}
}

static void	print_zeros(int *len, t_printf fl)
{
	int		j;

	if (fl.spe_c == 'p')
		ft_putcstr_len("0x", len, 2);
	if (fl.minus == 0 && fl.pad_c == '0')
		print_width(len, fl);
	if (fl.point == 1)
	{
		j = fl.precision;
		while (j-- > (int)fl.lenstr)
			*len += write(1, "0", 1);
	}
}

void	print_flags(int *len, t_printf fl)
{
	fl.lenstr = ft_strlen(fl.a);
	if (fl.nu2 == 0 && fl.point == 1 && fl.precision == 0)
		fl.width++;
	if (fl.spe_c == 'p')
		fl.width -= 2;
	if (fl.point == 1)
		fl.pad_c = ' ';
	if (fl.minus == 0 && fl.pad_c == ' ')
		print_width(len, fl);
	if (fl.sign == '-')
		*len += write(1, &fl.sign, 1);
	print_zeros(len, fl);
	if (!(fl.nu2 == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (fl.minus == 1)
		print_width(len, fl);
}