/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:31:45 by pmedina-          #+#    #+#             */
/*   Updated: 2020/11/03 10:13:15 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printuns(t_printf *j, unsigned int num)
{
	int			space;
	int			zero;
	int			len;

	len = intlen(num);
	j->precision = (j->precision < 0) ? len : j->precision;
	space = j->width - ((j->precision <= len) ? len : j->precision);
	space += (num == 0 && j->precision == 0 && j->dot == '.') ? 1 : 0;
	space -= (num < 0 && j->precision >= len) ? 1 : 0;
	zero = (j->precision > len) ? (j->precision - len) : 0;
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, ((j->zero_space != '0' ||
						(j->dot == '.' && j->precision >= 0)) ? " " : "0"), 1);
	while (zero--)
		j->lenstr += write(1, "0", 1);
	(j->precision == 0 && j->dot == '.' && num == 0) ? 0 : ft_putnbr_fd(num, 1);
	j->lenstr += len;
	if (j->tab == '-')
	{
		space++;
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
	if (num == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}
