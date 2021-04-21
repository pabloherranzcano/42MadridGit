/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:58 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/21 18:49:08 by pherranz         ###   ########.fr       */
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

typedef struct	s_printf
{
	char					*set;
	char					*setAux;
	char					spe_c;
	char					pad_c;
	char					minus;
	int						width;
	char					point;
	int						precision;
	char					sign;
	unsigned long long int	nu2;
	long long int			nu;
	char					*a;
	char					*str;
	size_t					lenstr;
	va_list					args;
	int						i;
}				t_printf;

typedef struct	s_ullitoa
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						baselen;
}				t_ullitoa;


int				ft_printf(const char *str, ...);
void			print_spec_pct(t_printf *st);
void			print_spec_c(t_printf *st, char c);
void			print_spec_s(t_printf *st, char *s);
void			print_spec_i_d_u(t_printf *st);
void			print_spec_x(t_printf *st);
void			print_spec_p(t_printf *st, unsigned long int p);
void			print_flags(t_printf *st);
size_t			ft_strlen(const char *s);
int				ft_strchr_01(char *s, char c);
void			ft_putcstr_len(char *s, t_printf *st, int size);
char			*ft_ullitoa_base(unsigned long long int n, char *base);

#endif
