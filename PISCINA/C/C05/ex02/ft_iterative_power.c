/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:41:01 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/25 19:46:49 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int i;
	int resultado;

	i = 0;
	resultado = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 0)
	{
		resultado = resultado * nb;
		power--;
		i++;
	}
	return (resultado);
}

int	main(void)
{
	int a;

	a = ft_iterative_power(15, 0);
	printf("%d", a);
	return (0);
}