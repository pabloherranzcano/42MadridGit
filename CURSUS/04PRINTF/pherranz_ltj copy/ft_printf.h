/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:25:17 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/19 18:36:16 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# define FLAGS		"-0"
# define ALL_FL		"-0*.0123456789"
# define FSPECS		"cspdiuxX%"
# define DIGITS		"0123456789"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"

typedef struct	s_printf
{
	char					set[14];
	char					spe_c;
	char					pad_c;
	char					minus;
	char					space;
	int						width;
	char					point;
	int						precision;
	char					sign;
	unsigned long long int	nu2;
	long long int			nu;
	char					*a;
	char					*str;
	size_t					strlen;
	va_list					args;
}				t_printf;

int				ft_printf(const char *str, ...);
void			print_spec_c(t_printf *h, char c);
void			print_spec_s(t_printf *h, char *s);
void			print_spec_pct(t_printf *h);
void			print_spec_i_d_u(t_printf *h);
void			print_spec_x(t_printf *h, va_list args);
void			print_spec_p(t_printf *h,unsigned long int p);
void			print_flags(t_printf *h);
size_t			ft_strlen(const char *s);
int				ft_strchr_01(char *s, char c);
void			ft_putcstr_len(char *s, int *len, int size);
char			*ft_ullitoa_base(unsigned long long int n, char *base);

#endif
