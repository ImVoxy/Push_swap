/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:42:59 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:43:02 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlist)
{
	t_list	*temp;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = newlist;
		else
		{
			temp = *alst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newlist;
		}
	}
}
