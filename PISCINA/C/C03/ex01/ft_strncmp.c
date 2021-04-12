/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:24:49 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/24 12:14:23 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((s1[i] != '\0' && s2[i]) != '\0' && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] != s2[i] && i < n)
		return (s1[i] - s2[i]);

	return (0);
}

int main(void)
{
	int a;
	char s1[] = "HOLaA";
	char s2[] = "HOLAa";

	int result;

	result = strncmp(s1, s2, 3);
	printf("La función original da una diferencia de: %d\n", result);
	
	a = ft_strncmp(s1, s2, 3);
	printf("La diferencia de bytes entre s1 y s2 es:  %d\n", a);

	return (0);
}
