/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:27:31 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/24 15:36:25 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i;
	int signo;
	int resultado;

	i = 0;
	signo = 1;
	resultado = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||\
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultado = resultado * 10 + (str[i] - 48);
		i++;
	}
	return (resultado * signo);
}

int	main(void)
{
	int		a;
	char	*str;

	str = "-++--2147483649";
	a = atoi(str);
	printf("%d\n", a);
	a = ft_atoi(str);
	printf("%d", a);
	return (0);
}
