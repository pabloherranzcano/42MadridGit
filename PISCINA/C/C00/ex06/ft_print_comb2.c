/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:39:44 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/20 20:53:18 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int a, int b);

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a >= 00 && a <= 98)
	{
		b = a + 1;
		while (b >= a && b <= 99)
		{
			print(a, b);
			b++;
		}
		a++;
	}
}

void	print(int a, int b)
{
	ft_putchar('0' + (a / 10));
	ft_putchar('0' + (a % 10));
	ft_putchar(' ');
	ft_putchar('0' + (b / 10));
	ft_putchar('0' + (b % 10));
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
    ft_print_comb2();
}
