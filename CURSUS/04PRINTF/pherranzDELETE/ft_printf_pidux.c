/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pidux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:44:01 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/24 22:55:47 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpointer(int *len, t_printf fl, unsigned long int p)
{
	fl.numstr = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, fl);
	free(fl.numstr);
}

void	printint(int *len, t_printf fl, va_list args)
{
	if (fl.cv == 'i' || fl.cv == 'd')
	{
		fl.numAux= va_arg(args, int);
		fl.sign = (fl.numAux>= 0) ? 0 : '-';
		fl.num = (fl.numAux>= 0) ? fl.numAux: -fl.numAux;
	}
	if (fl.cv == 'u')
	{
		fl.num = va_arg(args, unsigned int);
	}
	fl.numstr = ft_ullitoa_base(fl.num, DIGITS);
	print_flags(len, fl);
	free(fl.numstr);
}

void	print_spec_x(int *len, t_printf fl, va_list args)
{
	fl.num = va_arg(args, unsigned int);
	if (fl.cv == 'x')
		fl.numstr = ft_ullitoa_base(fl.num, HEXALOW);
	if (fl.cv == 'X')
		fl.numstr = ft_ullitoa_base(fl.num, HEXAUPP);
	print_flags(len, fl);
	free(fl.numstr);
}
