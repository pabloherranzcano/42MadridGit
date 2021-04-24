/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:12:52 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/24 19:48:52 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	flagdot(t_printf *j)
{
	if (*j->str == '.')
	{
		j->dot = '.';
		j->str++;
		if (*j->str == '*')
		{
			j->precision = va_arg(j->args, int);
		}
		if (ft_isdigit(*j->str))
		{
			j->precision = ft_atoi(j->str);
		}
	}
}

void	guessflags(t_printf *j)
{
	int	num;

	num = 0;
	if (*j->str == '0' && j->width == 0)
		j->zero_space = '0';
	if (*j->str == '-')
	{
		j->tab = '-';
		j->zero_space = ' ';
	}
	if (*j->str == '*')
	{
		num = va_arg(j->args, int);
		j->width = (num < 0) ? (num * -1) : num;
		if (num < 0)
			j->tab = '-';
	}
	if (ft_isdigit(*j->str) && *j->str != 0 && j->dot != '.' && j->width == 0)
		j->width = ft_atoi(j->str);
	flagdot(j);
}

void	initstruct(t_printf *j)
{
	j->width = 0;
	j->precision = 0;
	j->zero_space = ' ';
	j->dot = ' ';
	j->tab = ' ';
	while (!ft_isalpha(*j->str))
	{
		j->str++;
		guessflags(j);
		if (*j->str == '%')
			break ;
	}
}
