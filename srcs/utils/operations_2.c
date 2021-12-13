/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:10:40 by alpascal          #+#    #+#             */
/*   Updated: 2021/10/27 11:38:21 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotatea(t_head *head, t_config *config)
{
	t_stack	*tmp;

	tmp = head->a;
	if (head->a && head->a->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head->a;
		head->a = head->a->next;
		tmp->next->next = NULL;
		config->op += 1;
	}
	write(1, "ra\n", 3);
}

void	ft_rotateb(t_head *head, t_config *config)
{
	t_stack	*tmp;

	tmp = head->b;
	if (head->b && head->b->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head->b;
		head->b = head->b->next;
		tmp->next->next = NULL;
		config->op += 1;
	}
	write(1, "rb\n", 3);
}

void	ft_rev_rotatea(t_head *head, t_config *config)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = head->a;
	if (head->a && head->a->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp;
		tmp = tmp->next;
		tmp2->next = NULL;
		tmp->next = head->a;
		head->a = tmp;
		config->op += 1;
	}
	write(1, "rra\n", 4);
}

void	ft_rev_rotateb(t_head *head, t_config *config)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = head->b;
	if (head->b && head->b->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp;
		tmp = tmp->next;
		tmp2->next = NULL;
		tmp->next = head->b;
		head->b = tmp;
		config->op += 1;
	}
	write(1, "rrb\n", 4);
}
