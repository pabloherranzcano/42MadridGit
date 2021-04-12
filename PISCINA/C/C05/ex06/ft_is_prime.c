/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:44:13 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/26 10:19:58 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_is_prime(int nb)
{
	int n;

	n = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (nb % n != 0)
		n++;
	if (nb == n)
		return (1);
	return (0);
}

int	main(void)
{
	int a;

	a = ft_is_prime(47777);
	printf("%d", a);
	return (0);
}
