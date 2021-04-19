/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:47 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/19 19:25:48 by pherranz         ###   ########.fr       */
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
	t_ullitoa	params;

	params.b_len = ft_strlen(base);
	params.nbr = n;
	params.size = 1;
	n /= params.b_len;
	while (n)
	{
		params.size++;
		n /= params.b_len;
	}
	params.a = (char *)malloc(params.size + 1);
	if (!params.a)
		return (0);
	params.a[params.size--] = '\0';
	while (params.nbr > 0)
	{
		params.a[params.size--] = base[params.nbr % params.b_len];
		params.nbr /= params.b_len;
	}
	if (params.size == 0 && params.a[1] == '\0')
		params.a[0] = '0';
	return (params.a);
}
