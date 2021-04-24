/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:37 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 16:04:37 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	print_width(int *len, t_printf st)
{
	if (st.sign == '-')
		st.width--;
	if (st.precision <= st.numstr_len)
		st.precision = st.numstr_len;
	if (st.pad == '0' && st.minus == 1)
		st.pad = ' ';
	while (st.width > st.precision)
	{
		*len += write(1, &st.pad, 1);
		st.width--;
	}
}

static void	print_zeros(int *len, t_printf st)
{
	int		i;

	if (st.cv == 'p')
		ft_putstr_len("0x", len, 2);
	if (st.minus == 0 && st.pad == '0')
		print_width(len, st);
	if (st.point == 1)
	{
		i = st.precision;
		while (i-- > st.numstr_len)
			*len += write(1, "0", 1);
	}
}

void	print_flags(int *len, t_printf st)
{
	st.numstr_len = ft_strlen(st.numstr);
	if (st.num == 0 && st.point == 1 && st.precision == 0)
		st.width++;
	if (st.cv == 'p')
		st.width -= 2;
	if (st.point == 1)
		st.pad = ' ';
	if (st.minus == 0 && st.pad == ' ')
		print_width(len, st);
	if (st.sign == '-')
		*len += write(1, &st.sign, 1);
	print_zeros(len, st);
	if (st.num != 0 || st.point != 1 || st.precision != 0)
		ft_putstr_len(st.numstr, len, st.numstr_len);
	if (st.minus == 1)
		print_width(len, st);
}
