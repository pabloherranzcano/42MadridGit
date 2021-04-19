/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:48:50 by ltehedor          #+#    #+#             */
/*   Updated: 2021/04/19 18:13:00 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	treat_spec(t_printf *h)
{
	if (*h->spe_c == '%')
		print_spec_pct(&h);
	if (*h->spe_c == 'c')
		print_spec_c(&h, va_arg(args, int));
	if (*h->spe_c == 's')
		print_spec_s(&h, va_arg(args, char *));
	if (*h->spe_c == 'p')
		print_spec_p(&h, va_arg(args, unsigned long int));
	if (*h->spe_c == 'i' || *h->spe_c == 'd' || *h->spe_c == 'u')
		print_spec_i_d_u(&h);
	if (*h->spe_c == 'x' || *h->spe_c == 'X')
		print_spec_x(&h);
}

static void	treat_star(t_printf *h)
{
	int	value;

	(*h->str)++;
	value = va_arg(args, int);
	if (*h->point == 0)
	{
		*h->width = value;
		if (value <= 0)
			*h->width = -value;
		if (value <= 0) 
		*h->minus = 1;
	}
	if (*h->point == 1)
	{
		if (value >= 0)
			*h->precision = value;
		else
			*h->point = 0;
	}
}

static void	treat_flags(t_printf *h)
{
	while (ft_strchr_01(FLAGS, *h->set))
	{
		if (*h->set == '0')
			*h->pad_c = '0';
		*h->set++;
	}
	if (*h->set == '*')
		treat_star(&h);
	while (*h->set[h] != '\0' && ft_strchr_01(DIGITS, *h->set[h]))
		*h->width = 10 * *h->width + *h->set++ - '0';
	if (*h->set[h] == '.')
	{
		*h->point = 1;
		if (*h->set++ == '*')
			fl = treat_star(args, fl, &h);
		while (*h->set[h] != '\0' && ft_strchr_01(DIGITS, *h->set[h]))
			*h->precision = 10 * *h->precision + *h->set[h++] - '0';
	}
	return (fl);
}

static void		get_fspecs(t_printf *h)
{
	while (ft_strchr_01(ALL_FL, *h->str))
		*h->set++ = *h->str++;
	*h->set = '\0';
	if (ft_strchr_01(FSPECS, *h->str))
	{
		*h->spe_c = *h->str++;
		*h->minus = ft_strchr_01(*h->set, '-');
		*h->space = ft_strchr_01(*h->set, ' ');
		*h->width = 0;
		*h->point = 0;
		*h->precision = 0;
		*h->pad_c = ' ';
		fl = treat_flags(args, fl);
		treat_spec(args, len, fl);
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	h;

	h.str = (char *)format;
	va_start(h.args, format);
	h.lenstr = 0;
	while (*h.str != '\0')
	{
		if (*h.str != '%')
			len += write(1, &h.str++, 1);
		else
		{
			*h->str++;
			get_fspecs(&h);
		}
	}
	va_end(args);
	return (len);
}
