/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:43:15 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:43:18 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_lst;
	t_list	*temp;

	ptr_lst = *lst;
	while (ptr_lst)
	{
		temp = ptr_lst->next;
		del(ptr_lst->content);
		free(ptr_lst);
		ptr_lst = temp;
	}
	*lst = NULL;
}
