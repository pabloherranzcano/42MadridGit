/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:24 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 19:32:28 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	treat_spec(t_printf *st)
{
	if (st->spe_c == '%')
		print_spec_pct(st);
	if (st->spe_c == 'c')
		print_spec_c(st, va_arg(st->args, int));
	if (st->spe_c == 's')
		print_spec_s(st, va_arg(st->args, char *));
	if (st->spe_c == 'p')
		print_spec_p(st, va_arg(st->args, unsigned long int));
	if (st->spe_c == 'i' || st->spe_c == 'd' || st->spe_c == 'u')
		print_spec_i_d_u(st);
	if (st->spe_c == 'x' || st->spe_c == 'X')
		print_spec_x(st);
}

static void	treat_star(t_printf *st)
{
	int	value;

	st->setAux++;
	value = va_arg(st->args, int);
	if (st->point == 0)
	{
		st->width = value;
		if (value <= 0)
			st->width = -value;
		if (value <= 0)
			st->minus = 1;
	}
	if (st->point == 1)
	{
		if (value >= 0)
			st->precision = value;
		else
			st->point = 0;
	}
}

static void	treat_flags(t_printf *st)
{
	while (ft_strchr_01(FLAGS, *st->setAux))
	{
		if (*st->setAux == '0')
			st->pad_c = '0';
		st->setAux++;
	}
	if (*st->setAux == '*')
		treat_star(st);
	while (*st->setAux != '\0' && ft_strchr_01(DIGITS, *st->setAux))
	{
		st->width = 10 * st->width + *st->setAux - '0';
		st->setAux++;
	}
	if (*st->setAux == '.')
	{
		st->point = 1;
		st->set++;
		if (*st->set == '*')
			treat_star(st);
		while (*st->setAux != '\0' && ft_strchr_01(DIGITS, *st->setAux))
		{
			st->precision = 10 * st->precision + *st->setAux - '0';
			st->setAux++;
		}
	}
}

static void	initstruct(t_printf *st)
{
	st->setAux = st->set;
	while (ft_strchr_01(ALL_FLAGS, *st->str))
		*st->set++ = *st->str++;
	*st->set = '\0';
	if (ft_strchr_01(CONVERSIONS, *st->str))
	{
		st->spe_c = *st->str++;
		st->minus = ft_strchr_01(st->set, '-');
		st->width = 0;
		st->point = 0;
		st->precision = 0;
		st->pad_c = ' ';
		treat_flags(st);
		treat_spec(st);
	}
}

int	ft_printf(const char *format, ...)
{
	t_printf st;

	va_start(st.args, format);
	st.lenstr = 0;
	st.str = (char *)format;
	while (*st.str != '\0')
	{
		if (*st.str != '%')
			st.lenstr += write(1, st.str++, 1);
		else
		{
			st.str++;
			initstruct(&st);
		}
	}
	va_end(st.args);
	return (st.lenstr);
}
