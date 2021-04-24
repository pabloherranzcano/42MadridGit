/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:24 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 16:06:16 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	treat_cv(va_list args, int *len, t_printf st)
{
	if (st.cv == 'c')
		printchar(len, st, va_arg(args, int));
	if (st.cv == 's')
		printstring(len, st, va_arg(args, char *));
	if (st.cv == 'p')
		printdir(len, st, va_arg(args, unsigned long int));
	if (st.cv == 'd' || st.cv == 'i' || st.cv == 'u')
		printint(len, st, args);
	if (st.cv == 'x' || st.cv == 'X')
		printhexu(len, st, args);
	if (st.cv == '%')
		printchar(len, st, '%');
}

static t_printf	treat_star(va_list args, t_printf st, int *j)
{
	(*j)++;
	st.star = va_arg(args, int);
	if (st.point == 0)
	{
		st.width = st.star;
		if (st.star <= 0)
		{
			st.width = -st.star;
			st.minus = 1;
		}
	}
	if (st.point == 1)
	{
		if (st.star >= 0)
			st.precision = st.star;
		else
			st.point = 0;
	}
	return (st);
}

static t_printf	treat_flags(va_list args, t_printf st)
{
	int		j;

	j = 0;
	while (ft_strchr_01(FLAGS, st.flagset[j]))
	{
		if (st.flagset[j++] == '0')
			st.pad = '0';
	}
	if (st.flagset[j] == '*')
		st = treat_star(args, st, &j);
	while (st.flagset[j] != '\0' && ft_strchr_01(DIGITS, st.flagset[j]))
		st.width = 10 * st.width + st.flagset[j++] - '0';
	if (st.flagset[j] == '.')
	{
		st.point = 1;
		if (st.flagset[++j] == '*')
			st = treat_star(args, st, &j);
		while (st.flagset[j] != '\0' && ft_strchr_01(DIGITS, st.flagset[j]))
			st.precision = 10 * st.precision + st.flagset[j++] - '0';
	}
	return (st);
}

static void	initstruct(va_list args, const char *format, int *len, int *i)
{
	t_printf	st;
	int		j;

	j = 0;
	while (ft_strchr_01(ALL_FLAGS, format[*i]))
		st.flagset[j++] = format[(*i)++];
	st.flagset[j] = '\0';
	if (ft_strchr_01(CONVERSIONS, format[*i]))
	{
		st.cv = format[(*i)++];
		st.minus = ft_strchr_01(st.flagset, '-');
		st.width = 0;
		st.point = 0;
		st.precision = 0;
		st.pad = ' ';
		st = treat_flags(args, st);
		treat_cv(args, len, st);
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
			initstruct(st.args, st.str, &st.lenstr, &i);
		}
	}
	va_end(st.args);
	return (st.lenstr);
}
