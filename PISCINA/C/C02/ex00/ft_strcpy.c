/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:21:06 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/21 10:51:26 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		main(void)
{
	char src[] = "Hello World!";
	char dest[] = "PISTACHOOOOOOOS";

    strcpy(dest,src);
    printf("Dest de la función original: %s\n", dest);
    
	ft_strcpy(dest, src);
	printf("Dest de mi función:          %s\n", dest);
}
