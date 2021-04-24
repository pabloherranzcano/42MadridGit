/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:18:06 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/24 20:18:28 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# define FLAGS			"-0"
# define ALL_FLAGS		"-0*.0123456789"
# define CONVERSIONS	"cspdiuxX%"
# define DIGITS			"0123456789"
# define HEXALOW		"0123456789abcdef"
# define HEXAUPP		"0123456789ABCDEF"

typedef struct s_printf
{
	char					flagset[10];
	char					cv;
	char					pad;
	char					minus;
	int						width;
	char					point;
	int						precision;
	char					sign;
	int						star;
	unsigned long long int	num;
	long long int			numAux;
	char					*numstr;
	int						numstr_len;
	char					*str;
	int						lenstr;
	va_list					args;
}				t_printf;

typedef struct s_ullitoa
{
	char					*numstr;
	unsigned long long int	nbr;
	size_t					size;
	int						baselen;
}				t_ullitoa;

int				ft_printf(const char *str, ...);
void			printchar(int *len, t_printf st, char c);
void			printstring(int *len, t_printf st, char *s);
void			printint(int *len, t_printf st, va_list args);
void			printhexu(int *len, t_printf st, va_list args);
void			printdir(int *len, t_printf st, unsigned long int p);
void			print_flags(int *len, t_printf st);
size_t			ft_strlen(const char *s);
int				ft_strchr_01(char *s, char c);
void			ft_putstr_len(char *s, int *len, int size);
char			*ft_ullitoa_base(unsigned long long int n, char *base);

#endif
