/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:48:50 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/24 23:05:05 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_cv(va_list args, int *len, t_printf fl)
{
	if (fl.cv == '%')
		printchar(len, fl, '%');
	if (fl.cv == 'c')
		printchar(len, fl, va_arg(args, int));
	if (fl.cv == 's')
		printstring(len, fl, va_arg(args, char *));
	if (fl.cv == 'p')
		printpointer(len, fl, va_arg(args, unsigned long int));
	if (fl.cv == 'i' || fl.cv == 'd' || fl.cv == 'u')
		printint(len, fl, args);
	if (fl.cv == 'x' || fl.cv == 'X')
		printhex(len, fl, args);
}

static t_printf	treat_star(va_list args, t_printf fl, int *j)
{
	int	value;

	(*j)++;
	value = va_arg(args, int);
	if (fl.point == 0)
	{
		fl.width = (value >= 0) ? value : -value;
		fl.minus = (value >= 0) ? fl.minus : 1;
	}
	if (fl.point == 1)
	{
		if (value >= 0)
			fl.precision = value;
		else
			fl.point = 0;
	}
	return (fl);
}

static t_printf	treat_flags(va_list args, t_printf fl)
{
	int		j;

	j = 0;
	while (ft_strchr_01(FLAGS, fl.flagset[j]))
	{
		if (fl.flagset[j] == '0')
			fl.pad = '0';
		j++;
	}
	if (fl.flagset[j] == '*')
		fl = treat_star(args, fl, &j);
	while (fl.flagset[j] != '\0' && ft_strchr_01(DIGITS, fl.flagset[j]))
		fl.width = 10 * fl.width + fl.flagset[j++] - '0';
	if (fl.flagset[j] == '.')
	{
		fl.point = 1;
		if (fl.flagset[++j] == '*')
			fl = treat_star(args, fl, &j);
		while (fl.flagset[j] != '\0' && ft_strchr_01(DIGITS, fl.flagset[j]))
			fl.precision = 10 * fl.precision + fl.flagset[j++] - '0';
	}
	return (fl);
}

static void		get_fspecs(va_list args, const char *format, int *len, int *i)
{
	t_printf	fl;
	int		j;

	j = 0;
	while (ft_strchr_01(ALL_FLAGS, format[*i]))
		fl.flagset[j++] = format[(*i)++];
	fl.flagset[j] = '\0';
	if (ft_strchr_01(CONVERSIONS, format[*i]))
	{
		fl.cv = format[(*i)++];
		fl.minus = ft_strchr_01(fl.flagset, '-');
		fl.space = ft_strchr_01(fl.flagset, ' ');
		fl.width = 0;
		fl.point = 0;
		fl.precision = 0;
		fl.pad = ' ';
		fl = treat_flags(args, fl);
		treat_cv(args, len, fl);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar_len(format[i++], &len);
		else
		{
			i++;
			get_fspecs(args, format, &len, &i);
		}
	}
	va_end(args);
	return (len);
}
