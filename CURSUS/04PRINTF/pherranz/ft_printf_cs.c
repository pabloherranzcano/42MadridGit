/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:31 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 20:16:45 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_relleno(int *len, t_printf st)
{
	while (st.width > st.precision)
	{
		*len += write(1, &st.pad, 1);
		st.width--;
	}
}

void	printchar(int *len, t_printf st, char c)
{
	st.precision = 1;
	if (st.minus == 0)
		print_relleno(len, st);
	*len += write(1, &c, 1);
	if (st.minus == 1)
	{
		st.pad = ' ';
		print_relleno(len, st);
	}
}

void	printstring(int *len, t_printf st, char *s)
{
	if (s == NULL)
		s = "(null)";
	if ((st.point == 1 && st.precision > (int)ft_strlen(s)) || st.point == 0)
		st.precision = ft_strlen(s);
	if (st.minus == 0)
		print_relleno(len, st);
	ft_putstr_len(s, len, st.precision);
	if (st.minus == 1)
	{
		st.pad = ' ';
		print_relleno(len, st);
	}
}
