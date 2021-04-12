/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:36:35 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/23 21:45:23 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = (str[i] + 32);
		i++;
	}
	return (str);
}

int		main(void)
{
	char str[] = "Hola, mi NOMBRE es 8 Pablo";
	ft_strlowcase(str);
	printf("En mainúsculas: %s\n", str);
	return (0);
}
