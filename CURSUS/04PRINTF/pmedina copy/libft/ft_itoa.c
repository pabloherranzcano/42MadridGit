/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:03:17 by pmedina-          #+#    #+#             */
/*   Updated: 2020/11/13 13:05:21 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t		largo(long num)
{
	size_t				largo;

	largo = 0;
	if (num == 0)
	{
		largo++;
		return (largo);
	}
	if (num < 0)
	{
		num = num * -1;
		largo++;
	}
	while (num > 0)
	{
		num = num / 10;
		largo++;
	}
	return (largo);
}

char				*ft_itoa(int n)
{
	size_t			len;
	long			nu;
	char			*s;

	nu = n;
	len = largo(nu);
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (nu < 0)
	{
		s[0] = '-';
		nu = nu * -1;
	}
	while (nu > 0)
	{
		s[len] = (nu % 10) + '0';
		nu = nu / 10;
		len--;
	}
	return (s);
}
