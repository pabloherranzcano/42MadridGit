/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:54:07 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/12 19:25:49 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printchar(t_printf *j, int c)
{
	size_t	space;
	size_t	zero;

	space = 0;
	zero = 0;
	if (j->width > 0)
		space = (j->width - 1);
	if (j->zero_space == '0' && j->width > 0)
		zero = (j->width - 1);
	while (zero-- > 0 && j->tab != '-')
	{
		j->lenstr += write(1, "0", 1);
		space = 0;
	}
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, " ", 1);
	j->lenstr += write(1, &c, 1);
	if (j->tab == '-')
	{
		space++;
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
}
