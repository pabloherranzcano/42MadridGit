/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:24:49 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/24 12:13:13 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

int main(void)
{
	unsigned int a;
	char s1[] = "holA tio";
	char s2[] = "hola tio";

	a = strcmp(s1, s2);
	printf("La función original da una diferencia de: %d\n", a);

	a = ft_strcmp(s1, s2);
	printf("La diferencia de bytes entre s1 y s2 es:  %d\n", a);

	return (0);
}	
