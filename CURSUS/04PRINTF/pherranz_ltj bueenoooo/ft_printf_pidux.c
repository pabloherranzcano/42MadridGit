/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pidux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:42 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 17:03:17 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

void	print_spec_p(int *len, t_printf fl, unsigned long int p)
{
	fl.a = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_i_d_u(int *len, t_printf fl, va_list args)
{
	if (fl.spe_c == 'i' || fl.spe_c == 'd')
	{
		fl.nu = va_arg(args, int);
		if (fl.nu >= 0)
			fl.sign = 0;
		else
			fl.sign = '-';
		if (fl.nu >= 0)
			fl.nu2 = fl.nu;
		else
			fl.nu2 = -fl.nu;
	}
	if (fl.spe_c == 'u')
	{
		fl.nu2 = va_arg(args, unsigned int);
	}
	fl.a = ft_ullitoa_base(fl.nu2, DIGITS);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_x(int *len, t_printf fl, va_list args)
{
	fl.nu2 = va_arg(args, unsigned int);
	if (fl.spe_c == 'x')
		fl.a = ft_ullitoa_base(fl.nu2, HEXALOW);
	if (fl.spe_c == 'X')
		fl.a = ft_ullitoa_base(fl.nu2, HEXAUPP);
	print_flags(len, fl);
	free(fl.a);
}