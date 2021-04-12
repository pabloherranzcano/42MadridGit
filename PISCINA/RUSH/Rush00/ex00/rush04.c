/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:39:44 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/09 19:38:06 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((j == 1 && i == 1) || (j == x && i == y))
				ft_putchar('A');
			else if ((j == x && i == 1) || (j == 1 && i == y))
				ft_putchar('C');
			else if ((j > 1 && i > 1) && (j < x && i < y))
				ft_putchar(' ');
			else
				ft_putchar('B');
			j++;
		}
		ft_putchar(10);
		i++;
	}
}
