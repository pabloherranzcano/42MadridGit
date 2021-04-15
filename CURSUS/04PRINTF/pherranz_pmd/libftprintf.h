/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:16:23 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/15 17:23:27 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	char		*str;
	char		tab;
	char		dot;
	int			precision;
	int			lenstr;
	int			width;
	char		zero_space;
	va_list		args;
}				t_printf;

int				ft_printf(const char *s, ...);
void			initstruct(t_printf *j);
void			printchar(t_printf *j, int c);
void			printstring(t_printf *j, char *str);
void			printint(t_printf *j, int num);
void			printuns(t_printf *j, unsigned int num);
void			printhx(t_printf *j, unsigned int x);
void			printhexu(t_printf *j, unsigned int x);
void			printdir(t_printf *j, unsigned long dp);
int				ft_hxlen(unsigned long nb);
size_t			ft_intlen(long num);

#endif
