/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:24:49 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/24 11:28:45 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
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

	strcat(dest, src);
	printf("Dest retornada por la función original:   %s\n", dest);

	char dest2[50] = "Hello";
	char src2[] = " World!";
	
	ft_strcat(dest2, src2);
	printf("Dest retornada por mi función:            %s\n", dest2);
	
	return (0);
}