/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:59:42 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/24 19:50:38 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	transformhxmin(unsigned int x)
{
	char	c;

	if (x >= 16)
		transformhxmin(x / 16);
	x %= 16;
	c = (x < 10) ? (x + '0') : (x + 87);
	write(1, &c, 1);
}

void		printhx(t_printf *j, unsigned int x)
{
	int		space;
	int		zero;
	int		len;

	len = hxlen(x);
	j->precision = (j->precision < 0) ? len : j->precision;
	space = j->width - ((j->precision <= len) ? len : j->precision);
	space += (x == 0 && j->precision == 0 && j->dot == '.') ? 1 : 0;
	zero = (j->precision > len) ? j->precision - len : 0;
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, (j->zero_space != '0' || (j->dot == '.' &&
						j->precision >= 0) ? " " : "0"), 1);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	(j->precision == 0 && x == 0 && j->dot == '.')
		? 0 : transformhxmin(x);
	j->lenstr += len;
	if (j->tab == '-')
	{
		space++;
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
	if (x == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}
