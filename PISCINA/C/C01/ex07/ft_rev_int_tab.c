/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:30:18 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:27 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int aux;
	int i;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = aux;
		i++;
	}


for (i=0; i<size; i++)
{
    printf("%d, ", tab[i]);
}
}

int        main(void)
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    int i;
    int size;
    
    size = 10;
    
    i = 0;
    while (i < size)
    {
        
        printf("%d, ", tab[i]);
        i++;
    }
    printf("\n");
    
    
    ft_rev_int_tab(tab, 10);
}
