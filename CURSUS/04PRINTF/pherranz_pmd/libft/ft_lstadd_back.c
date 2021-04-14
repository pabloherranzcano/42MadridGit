/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:40:53 by pherranz          #+#    #+#             */
/*   Updated: 2020/10/30 11:03:30 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst && new)
	{
		current = *lst;
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (current->next)
				current = current->next;
			current->next = new;
			current->next->next = NULL;
		}
	}
}
