/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:52 by angonzal          #+#    #+#             */
/*   Updated: 2021/04/06 19:09:38 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This the principal function
*/

/*
** Function for "Flags" Struct Initialization
*/

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

/*
** If necessary set flags structure with valueslike "0,.,-,*" and "cspdiuxX%"
*/

int			ft_flags_set(const char *str_cpy, int i,
	t_flags *flags, va_list args)
{
	while (str_cpy[i])
	{
		if (!ft_isdigit(str_cpy[i]) && !ft_is_in_type_list(str_cpy[i])
		&& !ft_is_in_flags_list(str_cpy[i]))
			break ;
		if (str_cpy[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str_cpy[i] == '.')
			i = ft_flag_dot(str_cpy, i, flags, args);
		if (str_cpy[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (str_cpy[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str_cpy[i]))
			*flags = ft_flag_digit(str_cpy[i], *flags);
		if (ft_is_in_type_list(str_cpy[i]))
		{
			flags->type = str_cpy[i];
			break ;
		}
		i++;
	}
	return (i);
}

/*
** Function "ft_treat_str_cpy" to treat the argument, etc
** First:: Inicialiation flags structure in "ft_init_flags"
** Second:: if necessary set flags structure in "ft_flags_set"
** Third:: if necessary treatment flags structure  in "ft_treatment", and  write
*/

int			ft_treat_str_cpy(const char *str_cpy, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (i >= 0)
	{
		flags = ft_init_flags();
		if (!str_cpy[i])
			break ;
		else if (str_cpy[i] == '%' && str_cpy[i + 1])
		{
			i = ft_flags_set(str_cpy, ++i, &flags, args);
			if (ft_is_in_type_list(str_cpy[i]))
				char_count += ft_treatment(flags, args);
			else if (str_cpy[i])
				char_count += ft_putchar(str_cpy[i]);
		}
		else if (str_cpy[i] != '%')
			char_count += ft_putchar(str_cpy[i]);
		i++;
	}
	return (char_count);
}

/*
** ft_printf Initial function
** creation of va_list variable to treat the arguments
** and call to the function  "ft_treat_str_cpy" to treat the argument, etc
*/

int			ft_printf(const char *str, ...)
{
	const char	*str_cpy;
	va_list		args;
	int			char_count;

	str_cpy = ft_strdup(str);
	char_count = 0;
	va_start(args, str);
	char_count += ft_treat_str_cpy(str_cpy, args);
	va_end(args);
	free((char *)str_cpy);
	return (char_count);
}
