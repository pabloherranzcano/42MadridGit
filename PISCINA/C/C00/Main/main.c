/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:36:26 by slopez-p          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:33 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);
void    ft_print_alphabet(void);
void    ft_print_reverse_alphabet(void);
void    ft_print_numbers(void);
void    ft_is_negative(int n);
void	ft_print_comb(void);
void    ft_print_comb2(void);
void    ft_putnbr(int nb);

int		main(void)
{
	char a;
	int n;

	a = 'p';
	n = 1;
	printf("\nex00\n");
	ft_putchar(a);
	printf("\n\nex01\n");
	ft_print_alphabet();
	printf("\n\nex02\n");
	ft_print_reverse_alphabet();
	printf("\n\nex03\n");
	ft_print_numbers();
	printf("\n\nex04\n");
	n = 3;
	printf("=3\n");
	ft_is_negative(n);
	n = 0;
	printf("\n=0\n");
	ft_is_negative(n);
	n = -1;
	printf("\n=-1\n");
	ft_is_negative(n);
	printf("\n\nex05\n");
	ft_print_comb();
	printf("\n\nex06\n");
	sft_print_comb2();
	printf("\n\nex07\n");
	n = -2147483648;
	printf("numero %d \n", n);
	ft_putnbr(n);
	n = -10000;
	printf("\nnumero %d \n", n);
	ft_putnbr(n);
	n = 2147483647;
	printf("\nnumero %d \n", n);
	ft_putnbr(n);
	n = 0;
	printf("\nnumero %d \n", n);
	ft_putnbr(n);
//    n = 9;
//    while (n < 10)
//    {
//        ft_print_combn(n);
//        printf("\n");
//        n++;
//    }
//    return (0);
}
