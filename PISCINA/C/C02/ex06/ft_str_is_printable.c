/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:36:35 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/20 12:52:31 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

int		main(void)
{
	printf("Si la cadena sólo contiene caracteres imprimibles:   %d\n", ft_str_is_printable("hola, mi mail es pablo.hc9@gmail.com"));
	printf("Si la cadena no coniene sólo caracteres imprimibles: %d\n", ft_str_is_printable("Hola, soy español"));

	return (0);
}