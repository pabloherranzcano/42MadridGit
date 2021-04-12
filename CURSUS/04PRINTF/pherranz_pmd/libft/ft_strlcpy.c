/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:47:16 by pmedina-          #+#    #+#             */
/*   Updated: 2020/07/21 11:16:11 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t c;
	size_t t;
	size_t len;

	c = 0;
	if (!src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	t = dstsize - 1;
	while (t > 0 && src[c])
	{
		dst[c] = src[c];
		c++;
		t--;
	}
	dst[c] = '\0';
	return (len);
}
