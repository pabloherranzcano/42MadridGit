/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:26:06 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/24 19:49:48 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printsign(int signo)
{
	write(1, "-", 1);
	signo = 1;
	return (signo);
}

static void	printspaceback(t_printf *j, int space)
{
	if (j->tab == '-' && ++space)
	{
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
}

static void	writeint(t_printf *j, int zero, int space, int num)
{
	int		len;
	int		signo;
	char	*numstr;

	numstr = ft_itoa(num);
	len = intlen(num);
	signo = 0;
	if (num < 0 && space > j->precision && j->zero_space == '0' && numstr++)
		signo = printsign(signo);
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, (j->zero_space != '0' ||
					(j->dot == '.' && j->precision >= 0) ? " " : "0"), 1);
	if (num < 0 && signo == 0 && numstr++)
		signo = printsign(signo);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	len -= (signo == 1) ? 1 : 0;
	(j->precision == 0 && j->dot == '.' && num == 0)
		? 0 : write(1, numstr, len);
	printspaceback(j, space);
	if (num == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
		free((num >= 0) ? (numstr) : (--numstr));
}
	
void		printint(t_printf *j, int num)
{
	int		zero;
	int		space;
	int		len;

	len = intlen(num);
	j->lenstr += len;
	j->width = (j->precision == -1) ? len : j->width;
	j->precision = (j->precision == -1) ? len : j->precision;
	space = j->width - ((j->precision <= len) ? len : j->precision);
	space -= (num < 0 && j->precision >= len) ? 1 : 0;
	space += (num == 0 && j->precision == 0 && j->dot == '.') ? 1 : 0;
	zero = (num < 0 && j->precision >= 0) ? (j->precision - len + 1)
		: (j->precision - len);
	writeint(j, zero, space, num);
}
