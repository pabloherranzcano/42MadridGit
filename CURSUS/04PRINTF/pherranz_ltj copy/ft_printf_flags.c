/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:43:18 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/19 18:44:28 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(int *len, t_flags fl)
{
	if (*h->sign == '-' || *h->space == 1)
		*h->width--;
	if (*h->precision <= (int)*h->strlen)
		*h->precision = (int)*h->strlen;
	if (*h->pad_c == '0' && *h->minus == 1)
		*h->pad_c = ' ';
	while (*h->width > *h->precision)
	{
		*len += write(1, &*h->pad_c, 1);
		*h->width--;
	}
}

static void	print_zeros(int *len, t_flags fl)
{
	int		j;

	if (*h->spe_c == 'p')
		ft_putcstr_len("0x", len, 2);
	if (*h->minus == 0 && *h->pad_c == '0')
		print_width(len, fl);
	if (*h->point == 1)
	{
		j = *h->precision;
		while (j-- > (int)*h->strlen)
			*len += write(1, "0", 1);
	}
}

void		print_flags(t_printf *h)
{
	*h->strlen = ft_strlen(*h->a);
	if (*h->nu2 == 0 && *h->point == 1 && *h->precision == 0)
		*h->width++;
	if (*h->spe_c == 'p')
		*h->width -= 2;
	if (*h->point == 1)
		*h->pad_c = ' ';
	if (*h->minus == 0 && *h->pad_c == ' ')
		print_width(len, fl);
	if (*h->sign == '-')
		*len += write(1, &*h->sign, 1);
	if (*h->space == 1)
		*len += write(1, " ", 1);
	print_zeros(len, fl);
	if (!(*h->nu2 == 0 && *h->point == 1 && *h->precision == 0))
		ft_putcstr_len(*h->a, len, ft_strlen(*h->a));
	if (*h->minus == 1)
		print_width(len, fl);
}
