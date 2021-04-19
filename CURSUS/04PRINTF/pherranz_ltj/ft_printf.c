/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:24 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/19 19:25:26 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static void	treat_spec(va_list args, int *len, t_flags fl)
{
	if (fl.spe_c == '%')
		print_spec_pct(len, fl);
	if (fl.spe_c == 'c')
		print_spec_c(len, fl, va_arg(args, int));
	if (fl.spe_c == 's')
		print_spec_s(len, fl, va_arg(args, char *));
	if (fl.spe_c == 'p')
		print_spec_p(len, fl, va_arg(args, unsigned long int));
	if (fl.spe_c == 'i' || fl.spe_c == 'd' || fl.spe_c == 'u')
		print_spec_i_d_u(len, fl, args);
	if (fl.spe_c == 'x' || fl.spe_c == 'X')
		print_spec_x(len, fl, args);
}

static t_flags	treat_star(va_list args, t_flags fl, int *j)
{
	int	value;

	(*j)++;
	value = va_arg(args, int);
	if (fl.point == 0)
	{
		fl.width = value;
		if (value <= 0)
			fl.width = -value;
		if (value <= 0)
			fl.minus = 1;
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

static t_flags	treat_flags(va_list args, t_flags fl)
{
	int		j;

	j = 0;
	while (ft_strchr_01(FLAGS, fl.set[j]))
	{
		if (fl.set[j] == '0')
			fl.pad_c = '0';
		j++;
	}
	if (fl.set[j] == '*')
		fl = treat_star(args, fl, &j);
	while (fl.set[j] != '\0' && ft_strchr_01(DIGITS, fl.set[j]))
		fl.width = 10 * fl.width + fl.set[j++] - '0';
	if (fl.set[j] == '.')
	{
		fl.point = 1;
		if (fl.set[++j] == '*')
			fl = treat_star(args, fl, &j);
		while (fl.set[j] != '\0' && ft_strchr_01(DIGITS, fl.set[j]))
			fl.precision = 10 * fl.precision + fl.set[j++] - '0';
	}
	return (fl);
}

static void	get_fspecs(va_list args, const char *format, int *len, int *i)
{
	t_flags	fl;
	int		j;

	j = 0;
	while (ft_strchr_01(ALL_FL, format[*i]))
		fl.set[j++] = format[(*i)++];
	fl.set[j] = '\0';
	if (ft_strchr_01(FSPECS, format[*i]))
	{
		fl.spe_c = format[(*i)++];
		fl.minus = ft_strchr_01(fl.set, '-');
		fl.space = ft_strchr_01(fl.set, ' ');
		fl.width = 0;
		fl.point = 0;
		fl.precision = 0;
		fl.pad_c = ' ';
		fl = treat_flags(args, fl);
		treat_spec(args, len, fl);
	}
}

int	ft_printf(const char *format, ...)
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
			len += write(1, &format[i++], 1);
		else
		{
			i++;
			get_fspecs(args, format, &len, &i);
		}
	}
	va_end(args);
	return (len);
}
