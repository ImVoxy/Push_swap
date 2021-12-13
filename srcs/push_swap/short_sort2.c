/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:37:03 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/06 10:42:20 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_short_sort2(t_head *head, t_config *config, int s)
{
	while (s != 0)
	{
		if (s < 0)
		{
			ft_rev_rotatea(head, config);
			s++;
		}
		else
		{
			ft_rotatea(head, config);
			s--;
		}
	}
}
