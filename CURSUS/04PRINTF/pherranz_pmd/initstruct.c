/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:03:20 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/14 18:08:55 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		if (num < 0)
		{
			j->width = (num * -1);
			j->tab = '-';
		}
		j->width = num;
	}
	if (ft_isdigit(*j->str) && *j->str != 0 && j->dot != '.' && j->width == 0)
	{	
		j->width = ft_atoi(j->str);
	}
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
