/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:56:43 by pmedina-          #+#    #+#             */
/*   Updated: 2020/07/21 11:14:51 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(const char *s, char c)
{
	int		i;
	int		cs;

	i = 0;
	cs = 0;
	if (s[i] == c)
		cs--;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			cs++;
		i++;
	}
	cs++;
	return (cs);
}

static char	*ms(const char *s, char c)
{
	char	*string;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(string = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char		**ft_split(char const *s, char c)
{
	char	**tabla;
	int		ns;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	ns = str_count(s, c);
	if (!(tabla = (char **)malloc(sizeof(char *) * (ns + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tabla[i] = ms(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tabla[i] = NULL;
	return (tabla);
}
