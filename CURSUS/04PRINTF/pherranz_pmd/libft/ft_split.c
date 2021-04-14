/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:30:41 by pherranz          #+#    #+#             */
/*   Updated: 2020/11/05 18:39:20 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcounter(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
			count++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (count);
}

static char	*ft_strmalloc(const char *s, char c)
{
	char	*string;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(string = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
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
	int		num_w;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	num_w = ft_wordcounter(s, c);
	if (!(tabla = malloc(sizeof(char **) * (num_w + 1))))
		return (NULL);
	while (++i < num_w)
	{
		while (*s == c)
			s++;
		if (!(tabla[i] = ft_strmalloc(s, c)))
		{
			while (i > 0)
				free(tabla[i--]);
			free(tabla);
			return (0);
		}
		s += ft_strlen(tabla[i]);
	}
	tabla[i] = 0;
	return (tabla);
}
