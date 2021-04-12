/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:31:14 by pherranz          #+#    #+#             */
/*   Updated: 2020/11/05 16:52:32 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intcounter(long x)
{
	size_t	c;

	c = 0;
	if (x < 0)
		x = x * 10;
	if (x == 0)
		c = 1;
	while (x != 0)
	{
		x = x / 10;
		c++;
	}
	return (c);
}

char			*ft_itoa(int n)
{
	size_t	len;
	long	num;
	char	*dst;

	num = n;
	len = ft_intcounter(num);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len--] = 0;
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		dst[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (dst);
}
