/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:43:54 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:43:56 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;
	t_list	*n;

	list = NULL;
	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	if (n != NULL)
	{
		n->content = content;
		n->next = NULL;
	}
	list = n;
	return (list);
}
