/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:50:28 by pmedina-          #+#    #+#             */
/*   Updated: 2020/07/14 12:48:50 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*frase;
	size_t	i;
	size_t	st;

	i = 0;
	st = (size_t)start;
	if (!s)
		return (NULL);
	if (*s == '\0' || st > ft_strlen(s))
		return (ft_strdup(""));
	if (!(frase = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		frase[i] = s[st];
		i++;
		st++;
	}
	frase[i] = '\0';
	return (frase);
}
