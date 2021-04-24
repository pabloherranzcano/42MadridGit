/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:43:26 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 19:48:42 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ullitoa_base(unsigned long long int n)
{
	t_ullitoa	p;

	p.baselen = ft_strlen(base);
	p.nbr = n;
	p.size = 1;
	n /= p.baselen;
	while (n)
	{
		p.size++;
		n /= p.baselen;
	}
	p.numstr = (char *)malloc(p.size + 1);
	if (!p.numstr)
		return (0);
	p.size--;
	p.numstr[p.size] = '\0';
	while (p.nbr > 0)
	{
		p.numstr[p.size--] = base[p.nbr % p.baselen];
		p.nbr /= p.baselen;
	}
	if (p.size == 0 && p.numstr[1] == '\0')
		p.numstr[0] = '0';
	return (p.numstr);
}
