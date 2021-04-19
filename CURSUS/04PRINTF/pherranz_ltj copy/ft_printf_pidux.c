/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pidux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:44:01 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/19 18:59:29 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_p(t_printf *h, unsigned long int p)
{
	fl.a = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_i_d_u(t_printf *h)
{
	if (fl.spe_c == 'i' || fl.spe_c == 'd')
	{
		fl.nu = va_arg(args, int);
		if (fl.nu >= 0)
		 	fl.sign = 0;
		else
			fl.sign =  '-';
		if (fl.nu >= 0)
			fl.nu2 = fl.nu
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

void	print_spec_x(t_printf *h)
{
	*h->nu2 = va_arg(args, unsigned int);
	if (*h->spe_c == 'x')
		*h->a = ft_ullitoa_base(fl.nu2, HEXALOW);
	if (*h->spe_c == 'X')
		*h->a = ft_ullitoa_base(fl.nu2, HEXAUPP);
	print_flags(&h);
	free(fl.a);
}
