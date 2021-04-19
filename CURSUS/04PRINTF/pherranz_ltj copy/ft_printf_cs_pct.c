/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_pct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:58 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/19 18:45:55 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_relleno(t_printf *h)
{
	while (*h->width > *h->precision)
	{
		*len += write(1, &h->pad_c, 1);
		*h->width--;
	}
}

void		print_spec_pct(t_printf *h)
{
	*h->precision = 1;
	if (*h->minus == 0)
		print_relleno(&h);
	*len += write(1, "%", 1);
	if (*h->minus == 1)
	{
		*h->pad_c = ' ';
		print_relleno(&h);
	}
}

void		print_spec_c((t_printf *h, char c)
{
	*h->pad_c = ' ';
	*h->precision = 1;
	if (*h->minus == 0)
		print_relleno(len, fl);
	*len += write(1, &c, 1);
	if (*h->minus == 1)
		print_relleno(len, fl);
}

void		print_spec_s(t_printf **h, char *s)
{
	if (s == NULL)
		s = "(null)";
	if ((*h->point == 1 && *h->precision > (int)ft_strlen(s)) || *h->point == 0)
		*h->precision = ft_strlen(s);
	if (*h->minus == 0)
		print_relleno(len, fl);
	ft_putcstr_len(s, len, *h->precision);
	if (*h->minus == 1)
	{
		*h->pad_c = ' ';
		print_relleno(len, fl);
	}
}
