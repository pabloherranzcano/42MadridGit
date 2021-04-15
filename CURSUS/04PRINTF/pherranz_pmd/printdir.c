/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:22:14 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/15 17:20:23 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	transformhxmin(unsigned long x)
{
	char	c;

	if (x >= 16)
		transformhxmin(x / 16);
	x %= 16;
	if (x < 10)
		c = x + '0';
	else
		c = x + 87;
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

void	printdir(t_printf *j, unsigned long dp)
{
	int		space;
	int		zero;
	int		len;

	zero = 0;
	len = ft_hxlen(dp) + 2;
	if (j->precision < 0)
		j->precision = len;
	space = j->precision;
	if (j->precision <= len)
		space = len;
	if (j->precision == 0 && j->dot == '.' && j->width > 0)
		space = j->width - 2;
	if (j->precision > len)
		zero = (j->precision - len + 2);
	while (space-- > 0 && j->tab != '-')
	{
		if (j->zero_space != '0' || (j->dot == '.' && j->precision >= 0))
			j->lenstr += write(1, " ", 1);
		else
			j->lenstr += write(1, "0", 1);
	}
	write(1, "0x", 2);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	if (!(j->precision == 0 && dp == 0 && j->dot == '.'))
		transformhxmin(dp);
	j->lenstr += len;
	printspaceback(j, space);
	if (dp == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}
