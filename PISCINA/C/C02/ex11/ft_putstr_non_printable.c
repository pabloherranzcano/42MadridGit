/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:41:11 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/21 12:10:36 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	hexadecimal(unsigned int np)
{
	char *hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		hexadecimal(np / 16);
		hexadecimal(np % 16);
	}
	else
		write(1, &hex[np], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			hexadecimal(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int		main (void)
{
	char str[] = "Coucou\ntu vas bien ·? ESPAÑA España";
	ft_putstr_non_printable(str);

	return (0);
}
