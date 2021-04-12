/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:36:35 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/20 14:04:16 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if ((str[0] >= 97 && str[0] <= 122) || ((str[i] >= 97 &&\
		str[i] <= 122) && (str[i - 1] < 48 || (str[i - 1] > 57 &&
		str[i - 1] < 65) || (str[i - 1] > 90 && str[i - 1] < 97)\
		|| str[i - 1] > 122)))
			str[i] -= 32;
		i++;
	}
	return (str);
}

int		main(void)
{
	char str[] = "salut, comment tu vas \nhola? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("Las primeras letras en mayúsculas: %s\n", str);
	return (0);
}
