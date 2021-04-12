/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:44:14 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/06 20:32:45 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	setlenandprec(t_printf *j, int len)
{
	if (j->precision < 0)
		j->precision = len;
	if (j->precision != 0 && j->precision < len)
		len -= (len - j->precision);
	if (j->precision == 0 && j->dot == '.' && j->width == 0)
		len -= len;
	if (j->precision == 0 && j->dot == '.'
		&& j->width > 0 && j->zero_space == ' ')
		len -= len;
	return (len);
}

void	pst(t_printf *j, char *str, size_t len)
{
	if (j->dot == '.' && j->precision == 0)
		j->lenstr += write(1, str, 0);
	else
		j->lenstr += write(1, str, len);
}

void	printstring(t_printf *j, char *str)
{
	int		space;
	int		zero;
	int		len;

	zero = 0;
	space = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = setlenandprec(j, len);
	if (j->width > 0)
		space = j->width - len;
	if (j->tab != '-' && j->zero_space == '0')
		zero = j->width - len;
	while (zero-- > 0 && j->tab != '-')
	{
		j->lenstr += write(1, "0", 1);
		space = 0;
	}
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, " ", 1);
	if (!(j->precision == 0 && j->dot == '.' && str == 0))
		pst(j, str, len);
	if (j->tab == '-' && ++space)
	{
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
}
