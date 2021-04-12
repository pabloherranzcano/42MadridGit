/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:24:49 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/24 11:28:41 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
	
int main(void)
{
	char dest[50] = "Hello";
	char src[] = " World!";

	strncat(dest, src, 2);
	printf("Dest retornada por la función strcat:   %s\n", dest);

	char dest2[50] = "Hello";
	char src2[] = " World!";

	ft_strncat(dest2, src2, 2);
	printf("Dest retornada por mi función: 			%s\n", dest2);
	
	return (0);
}