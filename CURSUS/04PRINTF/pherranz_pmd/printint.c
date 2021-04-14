/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:26:06 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/14 19:27:22 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	len = ft_intlen(num);
	signo = 0;
	if (num < 0 && space > j->precision && j->zero_space == '0' && numstr++)
		signo = printsign(signo);
	while (space-- > 0 && j->tab != '-')
	{
		if (j->zero_space != '0' || (j->dot == '.' && j->precision >= 0))
			j->lenstr += write(1, " ", 1);
		else
			j->lenstr += write(1, "0", 1);
	}
	if (num < 0 && signo == 0 && numstr++)
		signo = printsign(signo);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	if (signo == 1)
		len -= 1;
	if (!(j->precision == 0 && j->dot == '.' && num == 0))
		write(1, numstr, len);
	printspaceback(j, space);
	if (num == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
	if (num >= 0)
		free(numstr);
	else
		free(--numstr);
}

void	printint(t_printf *j, int num)
{
	int		zero;
	int		space;
	int		len;

	len = ft_intlen(num);
	j->lenstr += len;
	if (j->precision < 0)
	{
		j->width = len;
		j->precision = len;
	}
	space = j->width - j->precision;
	if (j->precision <= len)
		space = j->width - len;
	if (num < 0 && j->precision >= len)
		space--;
	if (num == 0 && j->precision == 0 && j->dot == '.')
		space++;
	zero = (j->precision - len);
	if (num < 0 && j->precision >= 0)
		zero = (j->precision - len + 1);
	writeint(j, zero, space, num);
}
