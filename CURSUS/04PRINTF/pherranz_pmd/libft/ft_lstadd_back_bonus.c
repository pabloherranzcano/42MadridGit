/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:58:52 by pmedina-          #+#    #+#             */
/*   Updated: 2020/07/22 13:15:04 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pr;

	if (lst && new)
	{
		pr = *lst;
		if (pr == NULL)
			*lst = new;
		else
		{
			while (pr->next)
				pr = pr->next;
			pr->next = new;
		}
	}
}
