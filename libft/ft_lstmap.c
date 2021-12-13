/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:43:47 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:43:49 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_list_init(t_list *lst, t_list *new_list, void *(*f)(void*))
{
	t_list	*new_node;

	new_node = new_list;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_list;

	new_list = NULL;
	new_list = ft_list_init(lst, new_list, f);
	if (!new_list)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	return (new_list);
}
