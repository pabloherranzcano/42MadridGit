/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:53:29 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/25 20:12:42 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int n;

	n = 3;
	if (nb <= 1)
		return (2);
	if (nb == 2)
		return (2);
	while (nb % n != 0)
		n += 2;
	if (nb == n)
		return (nb);
	return (ft_find_next_prime(nb + 1));
}

int	main(void)
{
	int a;

	a = ft_find_next_prime(2147483634);
	printf("%d", a);
	return (0);
}
