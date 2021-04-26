/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pidux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:42 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 23:24:22 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpointer(int *len, t_printf st, unsigned long int p)
{
	st.numstr = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, st);
	free(st.numstr);
}

void	printint(int *len, t_printf st, va_list args)
{
	if (st.cv == 'i' || st.cv == 'd')
	{
		st.numAux = va_arg(args, int);
		st.sign = '-';
		st.num = -st.numAux;
		if (st.numAux >= 0)
		{
			st.sign = 0;
			st.num = st.numAux;
		}
	}
	if (st.cv == 'u')
		st.num = va_arg(args, unsigned int);
	st.numstr = ft_ullitoa_base(st.num, DIGITS);
	print_flags(len, st);
	free(st.numstr);
}

void	printhexu(int *len, t_printf st, va_list args)
{
	st.num = va_arg(args, unsigned int);
	if (st.cv == 'x')
		st.numstr = ft_ullitoa_base(st.num, HEXALOW);
	if (st.cv == 'X')
		st.numstr = ft_ullitoa_base(st.num, HEXAUPP);
	print_flags(len, st);
	free(st.numstr);
}
