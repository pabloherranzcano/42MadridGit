/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:24 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 17:29:08 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	treat_cv(t_printf *st)
{
	if (st->cv == 'c')
		printchar(st, va_arg(st->args, int));
	if (st->cv == 's')
		printstring(st, va_arg(st->args, char *));
	if (st->cv == 'p')
		printdir(st, va_arg(st->args, unsigned long int));
	if (st->cv == 'd' || st->cv == 'i' || st->cv == 'u')
		printint(st, st->args);
	if (st->cv == 'x' || st->cv == 'X')
		printhexu(st, st->args);
	if (st->cv == '%')
		printchar(st, '%');
}

static void	treat_star(t_printf *st, int *j)
{
	(*j)++;
	st->star = va_arg(st->args, int);
	if (st->point == 0)
	{
		st->width = st->star;
		if (st->star <= 0)
		{
			st->width = -st->star;
			st->minus = 1;
		}
	}
	if (st->point == 1)
	{
		if (st->star >= 0)
			st->precision = st->star;
		else
			st->point = 0;
	}
}

static void	treat_flags(t_printf *st)
{
	int		j;

	j = 0;
	while (ft_strchr_01(FLAGS, st->flagset[j]))
	{
		if (st->flagset[j++] == '0')
			st->pad = '0';
	}
	if (st->flagset[j] == '*')
		treat_star(st, &j);
	while (st->flagset[j] != '\0' && ft_strchr_01(DIGITS, st->flagset[j]))
		st->width = 10 * st->width + st->flagset[j++] - '0';
	if (st->flagset[j] == '.')
	{
		st->point = 1;
		if (st->flagset[++j] == '*')
			treat_star(st, &j);
		while (st->flagset[j] != '\0' && ft_strchr_01(DIGITS, st->flagset[j]))
			st->precision = 10 * st->precision + st->flagset[j++] - '0';
	}
}

static void	initstruct(t_printf *st, int *i)
{
	int		j;

	j = 0;
	while (ft_strchr_01(ALL_FLAGS, st->str[*i]))
		st->flagset[j++] = st->str[(*i)++];
	st->flagset[j] = '\0';
	if (ft_strchr_01(CONVERSIONS, st->str[*i]))
	{
		st->cv = st->str[(*i)++];
		st->minus = ft_strchr_01(st->flagset, '-');
		st->width = 0;
		st->point = 0;
		st->precision = 0;
		st->pad = ' ';
		treat_flags(st);
		treat_cv(st);
	}
}

int	ft_printf(const char *format, ...)
{
	t_printf st;
	int		i;

	st.str = (char *)format;
	st.lenstr = 0;
	va_start(st.args, format);
	i = 0;
	while (st.str[i] != '\0')
	{
		if (st.str[i] != '%')
			st.lenstr += write(1, &st.str[i++], 1);
		else
		{
			i++;
			initstruct(&st, &i);
		}
	}
	va_end(st.args);
	return (st.lenstr);
}
