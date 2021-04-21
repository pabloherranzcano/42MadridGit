/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:47 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 17:07:23 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	ft_strchr_01(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

void	ft_putcstr_len(char *s, int *len, int size)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] && i < size)
			*len += write(1, &s[i++], 1);
	}
}

char	*ft_ullitoa_base(unsigned long long int n, char *base)
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
	p.a = (char *)malloc(p.size + 1);
	if (!p.a)
		return (0);
	p.a[p.size--] = '\0';
	while (p.nbr > 0)
	{
		p.a[p.size--] = base[p.nbr % p.baselen];
		p.nbr /= p.baselen;
	}
	if (p.size == 0 && p.a[1] == '\0')
		p.a[0] = '0';
	return (p.a);
}
