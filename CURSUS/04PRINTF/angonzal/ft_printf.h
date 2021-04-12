/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:44:44 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/20 17:31:42 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
int					ft_treatment(t_flags flags, va_list args);
int					ft_treat_width(int width, int minus, int has_zero);
int					ft_treat_str_prec(char *str, int prec);
int					ft_treat_c_option(char c, t_flags flags);
int					ft_treat_s_option(char *str, t_flags flags);
int					ft_treat_d_i_option(int i, t_flags flags);
int					ft_treat_percent_option(t_flags flags);
int					ft_treat_x_option(unsigned int ui, int lower, t_flags flags);
int					ft_treat_u_option(unsigned int unsi, t_flags flags);
int					ft_treat_p_option(unsigned long long pointer, t_flags flags);

int					ft_putchar(int c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_str_tolower(char *str);

int					ft_flag_dot(const char *save, int start,
					t_flags *flags, va_list args);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

#endif
