/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:21:16 by pmedina-          #+#    #+#             */
/*   Updated: 2020/07/27 11:37:25 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*e;

	if (!f || !lst)
		return (NULL);
	lista = NULL;
	while (lst)
	{
		if (!(e = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lista, del);
		}
		ft_lstadd_back(&lista, e);
		lst = lst->next;
	}
	return (lista);
}
