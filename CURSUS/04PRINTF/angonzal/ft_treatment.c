/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:32 by angonzal          #+#    #+#             */
/*   Updated: 2021/03/20 17:20:49 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function is for general processing, and to call different functions
** depending on the option; in addition there are a couple of functions to
** validate flags and functions.
*/

int		ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_treatment(t_flags flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (flags.type == 'c')
		char_count = ft_treat_c_option(va_arg(args, int), flags);
	else if (flags.type == 's')
		char_count = ft_treat_s_option(va_arg(args, char *), flags);
	else if (flags.type == 'p')
		char_count = ft_treat_p_option(va_arg(args, unsigned long long), flags);
	else if (flags.type == 'd' || flags.type == 'i')
		char_count = ft_treat_d_i_option(va_arg(args, int), flags);
	else if (flags.type == 'u')
		char_count += ft_treat_u_option((unsigned int)va_arg(args,
		unsigned int), flags);
	else if (flags.type == 'x')
		char_count += ft_treat_x_option(va_arg(args, unsigned int), 1, flags);
	else if (flags.type == 'X')
		char_count += ft_treat_x_option(va_arg(args, unsigned int), 0, flags);
	else if (flags.type == '%')
		char_count += ft_treat_percent_option(flags);
	return (char_count);
}
