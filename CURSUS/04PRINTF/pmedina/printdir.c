/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:22:14 by pmedina-          #+#    #+#             */
/*   Updated: 2020/11/13 13:09:59 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	transformhxmin(unsigned long x)
{
	char	c;

	if (x >= 16)
		transformhxmin(x / 16);
	x %= 16;
	c = (x < 10) ? (x + '0') : (x + 87);
	write(1, &c, 1);
}

static void	printspaceback(t_printf *j, int space)
{
	if (j->tab == '-' && ++space)
	{
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
}

void		printdir(t_printf *j, unsigned long dp)
{
	int		space;
	int		zero;
	int		len;

	len = hxlen(dp) + 2;
	j->precision = (j->precision < 0) ? len : j->precision;
	space = j->width - ((j->precision <= len) ? len : j->precision);
	space = (j->precision == 0 && j->dot == '.' && j->width > 0)
	? j->width - 2 : space;
	zero = (j->precision > len) ? (j->precision - len + 2) : 0;
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, (j->zero_space != '0' ||
					(j->dot == '.' && j->precision >= 0) ? " " : "0"), 1);
	write(1, "0x", 2);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	(j->precision == 0 && dp == 0 && j->dot == '.')
		? 0 : transformhxmin(dp);
	j->lenstr += len;
	printspaceback(j, space);
	if (dp == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}
