/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:07:24 by alpascal          #+#    #+#             */
/*   Updated: 2021/10/27 11:37:05 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swapa(t_head *head, t_config *config)
{
	t_stack	*tmp;

	if (head->a && head->a->next)
	{
		tmp = head->a->next;
		head->a->next = head->a->next->next;
		tmp->next = head->a;
		head->a = tmp;
		config->op += 1;
	}
	write(1, "sa\n", 3);
}

void	ft_swapb(t_head *head, t_config *config)
{
	t_stack	*tmp;

	if (head->b && head->b->next)
	{
		tmp = head->b->next;
		head->b->next = head->b->next->next;
		tmp->next = head->b;
		head->b = tmp;
		config->op += 1;
	}
	write(1, "sb\n", 3);
}

void	ft_pusha(t_head *head, t_config *config)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	if (head->b)
	{
		tmpa = head->a;
		tmpb = head->b;
		head->b = tmpb->next;
		tmpb->next = head->a;
		head->a = tmpb;
		config->op += 1;
	}
	write(1, "pa\n", 3);
}

void	ft_pushb(t_head *head, t_config *config)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	if (head->a)
	{
		tmpa = head->b;
		tmpb = head->a;
		head->a = tmpb->next;
		tmpb->next = head->b;
		head->b = tmpb;
		config->op += 1;
	}
	write(1, "pb\n", 3);
}
