/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:31:45 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/14 18:28:36 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printuns(t_printf *j, unsigned int num)
{
	int			space;
	int			zero;
	int			len;

	len = ft_intlen(num);
	space = j->width - j->precision;
	if (j->precision < 0)
		j->precision = len;
	if (j->precision <= len)
		space = j->width - len;
	if (num == 0 && j->precision == 0 && j->dot == '.')
		space++;
	if (num < 0 && j->precision >= len)
		space--;
	if (j->precision > len)
		zero = j->precision - len;
	while (space-- > 0 && j->tab != '-')
	{
		if (j->zero_space != '0' || (j->dot == '.' && j->precision >= 0))
			j->lenstr += write(1, " ", 1);
		else
			j->lenstr += write(1, "0", 1);
	}
	while (zero--)
		j->lenstr += write(1, "0", 1);
	if (!(j->precision == 0 && j->dot == '.' && num == 0))
		ft_putnbr_fd(num, 1);
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
