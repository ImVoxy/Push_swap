/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:08:06 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/13 01:42:06 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	test_write(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a;
	write(1, "-> test stack a\n", 16);
	while (tmp)
	{
		ft_putnbr_fd(tmp->val, 1);
		tmp = tmp->next;
		write(1, " ", 1);
	}
	write(1, "\n\n", 2);
	write(1, "-> test stack b\n", 16);
	tmp = head->b;
	while (tmp)
	{
		ft_putnbr_fd(tmp->val, 1);
		tmp = tmp->next;
		write(1, " ", 1);
	}
	write(1, "\n\n", 2);
}

int	loop_solver(t_head *head, t_config *config)
{
	if (config->count <= 1)
		return (0);
	else if (config->count == 2)
	{
		if (head->a->val > head->a->next->val)
			ft_swapa(head, config);
	}
	else if (config->count <= 5)
		ft_short_sort(head, config, 0, 0);
	else
		quick_sort(head, config);
	return (0);
}

int	main(int argc, char **argv)
{
	t_head		*head;
	t_config	*config;
	int			*tab;

	(void)argc;
	tab = check_args(&(argv[1]));
	if (tab)
	{
		head = ft_calloc(1, sizeof(t_head));
		config = ft_calloc(1, sizeof(t_config));
		if (count_args(&(argv[1]), 0) > 1)
		{
			init_stack(count_args(&(argv[1]), 0), tab, &head);
			parse_stack(head->a, config);
			loop_solver(head, config);
		}
		ft_cleanup(head, config, tab);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
