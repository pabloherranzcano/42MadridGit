/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:43:18 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/24 22:55:13 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(int *len, t_printf fl)
{
	if (fl.sign == '-' || fl.space == 1)
		fl.width--;
	if (fl.precision <= (int)fl.numstr_len)
		fl.precision = (int)fl.numstr_len;
	if (fl.pad == '0' && fl.minus == 1)
		fl.pad = ' ';
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad, len);
		fl.width--;
	}
}

static void	print_zeros(int *len, t_printf fl)
{
	int		j;

	if (fl.cv == 'p')
		ft_putcstr_len("0x", len, 2);
	if (fl.minus == 0 && fl.pad == '0')
		print_width(len, fl);
	if (fl.point == 1)
	{
		j = fl.precision;
		while (j-- > (int)fl.numstr_len)
			ft_putchar_len('0', len);
	}
}

void		print_flags(int *len, t_printf fl)
{
	fl.numstr_len = ft_strlen(fl.numstr);
	if (fl.num == 0 && fl.point == 1 && fl.precision == 0)
		fl.width++;
	if (fl.cv == 'p')
		fl.width -= 2;
	if (fl.point == 1)
		fl.pad = ' ';
	if (fl.minus == 0 && fl.pad == ' ')
		print_width(len, fl);
	if (fl.sign == '-')
		ft_putchar_len(fl.sign, len);
	if (fl.space == 1)
		ft_putchar_len(' ', len);
	print_zeros(len, fl);
	if (!(fl.num == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.numstr, len, ft_strlen(fl.numstr));
	if (fl.minus == 1)
		print_width(len, fl);
}
