/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:47:58 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/25 19:44:58 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int resultado;

	resultado = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		resultado = resultado * nb;
		nb--;
	}
	return (resultado);
}

int	main(void)
{
	int a;

	a = ft_iterative_factorial(15);
	printf("%d", a);
	return (0);
}
