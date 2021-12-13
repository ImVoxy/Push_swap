/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:23:13 by alpascal          #+#    #+#             */
/*   Updated: 2021/10/27 11:38:52 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swaps(t_head *head, t_config *config)
{
	ft_swapa(head, config);
	ft_swapb(head, config);
	write(1, "ss\n", 3);
	config->op -= 1;
}

void	ft_rotater(t_head *head, t_config *config)
{
	ft_rotatea(head, config);
	ft_rotateb(head, config);
	write(1, "rr\n", 3);
	config->op -= 1;
}

void	ft_rev_rotater(t_head *head, t_config *config)
{
	ft_rev_rotatea(head, config);
	ft_rev_rotateb(head, config);
	write(1, "rrr\n", 4);
	config->op -= 1;
}
