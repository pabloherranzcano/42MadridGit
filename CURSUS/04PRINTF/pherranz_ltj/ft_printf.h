/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:25:58 by pherranz          #+#    #+#             */
/*   Updated: 2021/04/19 19:26:03 by pherranz         ###   ########.fr       */
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

typedef struct	s_flags
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
	size_t					strlen;
}				t_flags;

typedef struct	s_ullitoa
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;
}				t_ullitoa;


int				ft_printf(const char *str, ...);
void			print_spec_c(int *len, t_flags fl, char c);
void			print_spec_s(int *len, t_flags fl, char *s);
void			print_spec_pct(int *len, t_flags fl);
void			print_spec_i_d_u(int *len, t_flags fl, va_list args);
void			print_spec_x(int *len, t_flags fl, va_list args);
void			print_spec_p(int *len, t_flags fl, unsigned long int p);
void			print_flags(int *len, t_flags fl);
size_t			ft_strlen(const char *s);
int				ft_strchr_01(char *s, char c);
void			ft_putcstr_len(char *s, int *len, int size);
char			*ft_ullitoa_base(unsigned long long int n, char *base);

#endif
