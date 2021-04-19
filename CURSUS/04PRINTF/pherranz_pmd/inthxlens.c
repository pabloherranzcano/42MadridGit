/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:55:08 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/15 17:04:30 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_intlen(long num)
{
	size_t	c;

	c = 0;
	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		num *= -1;
		c++;
	}
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

int	ft_hxlen(unsigned long nb)
{
	int	count;

	count = 0;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	if (nb >= 0)
		count++;
	return (count);
}
