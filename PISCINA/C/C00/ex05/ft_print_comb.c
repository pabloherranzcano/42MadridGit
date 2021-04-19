/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:39:44 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/10 22:38:33 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0';
	while ((i >= '0' && i <= '7') && (i != j && i != k))
	{
		j = i + 1;
		while ((j >= '0' && j <= '8') && (j != k && j != i))
		{
			k = j + 1;
			while ((k >= '0' && k <= '9') && (k != i && k != j))
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if (!(i == '7' && j == '8' && k == '9'))
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}