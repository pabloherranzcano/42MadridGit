/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pidux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:42 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 18:58:58 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

void	print_spec_p(t_printf *st, unsigned long int p)
{
	st->a = ft_ullitoa_base(p, HEXALOW);
	print_flags(st);
	free(st->a);
}

void	print_spec_i_d_u(t_printf *st)
{
	if (st->spe_c == 'i' || st->spe_c == 'd')
	{
		st->nu = va_arg(st->args, int);
		if (st->nu >= 0)
			st->sign = 0;
		else
			st->sign = '-';
		if (st->nu >= 0)
			st->nu2 = st->nu;
		else
			st->nu2 = -st->nu;
	}
	if (st->spe_c == 'u')
	{
		st->nu2 = va_arg(st->args, unsigned int);
	}
	st->a = ft_ullitoa_base(st->nu2, DIGITS);
	print_flags(st);
	free(st->a);
}

void	print_spec_x(t_printf *st)
{
	st->nu2 = va_arg(st->args, unsigned int);
	if (st->spe_c == 'x')
		st->a = ft_ullitoa_base(st->nu2, HEXALOW);
	if (st->spe_c == 'X')
		st->a = ft_ullitoa_base(st->nu2, HEXAUPP);
	print_flags(st);
	free(st->a);
}
