/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:36:23 by pherranz          #+#    #+#             */
/*   Updated: 2020/07/02 10:23:41 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	j = 0;
	if (size != 0)
	{
		while (src[j] != '\0' && j < (size - 1))
		{
			dest[j] = src[j];
			j++;
		}
	}
	dest[i] = '\0';
	return (i);
}

int				main(void)	
{
	char src[] = "Hello45896525468";
	char dest[] = "PISTACHOOOOOOOOOOOOOS";
	unsigned int a;

	a = strlcpy(dest, src, 0);
	printf("Dest de la función original:  %d\n", a);
	printf("Dest de la función original:  %s\n", dest);

	a = ft_strlcpy(dest, src, 0);
	printf("Dest de mi función:           %d\n", a);
	printf("Dest de mi función:           %s\n", dest);
	
	return 0;
}