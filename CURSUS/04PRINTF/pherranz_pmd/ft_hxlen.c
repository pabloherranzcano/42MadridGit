/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:54:02 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/15 17:36:56 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_hxlen(unsigned long nb)
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
