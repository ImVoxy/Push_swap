/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:21 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/10 18:10:27 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	min_val(t_head *head, t_config *config, int max)
{
	int	*tab;
	int	val;
	int	i;
	int	spot;

	spot = 0;
	i = 0;
	val = head->a->val;
	tab = sorted_tab(head->a, config, 0, 0);
	while (i < max)
	{
		if (tab[i] < val)
		{
			val = tab[i];
			spot = i;
		}
		i++;
	}
	if (spot <= max / 2)
		while (spot-- > 0)
			ft_rotatea(head, config);
	else
		while (spot++ < max)
			ft_rev_rotatea(head, config);
	free(tab);
}

int	check_limits(int *tab, int val, int max)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = tab[0];
	k = tab[0];
	while (i < max)
	{
		if (tab[i] < j)
			j = tab[i];
		if (tab[i] > k)
			k = tab[i];
		i++;
	}
	if (val > k)
		return (1);
	else if (val < j)
		return (-1);
	else
		return (0);
}

void	ft_threesort(t_head *head, t_config *config)
{
	if (head->a->val > head->a->next->val)
		ft_swapa(head, config);
	if (head->a->val > head->a->next->next->val)
		ft_rev_rotatea(head, config);
	if (head->a->next->val > head->a->next->next->val)
	{
		ft_rev_rotatea(head, config);
		ft_swapa(head, config);
	}
}

int	ft_path_finder(int *tab, int max, t_head *head, t_config *config)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (check_limits(tab, head->b->val, max) != 0)
	{
		min_val(head, config, max);
		return (0);
	}
	while (i < max && !(head->b->val > tab[i - 1]
			&& head->b->val < tab[i]))
		i++;
	while (k < max - 1 && !(head->b->val > tab[max - 2 - k]
			&& head->b->val < tab[max - 1 - k]))
		k++;
	if (i == max)
		return (0);
	if (k < i)
		return (-k - 1);
	return (i);
}

void	ft_short_sort(t_head *head, t_config *config, int j, int i)
{
	int	*tab;
	int	s;

	j = 0;
	i = 0;
	while (i++ + 3 < config->count)
		ft_pushb(head, config);
	ft_threesort(head, config);
	i = 0;
	while (config->count - i > 3)
	{
		tab = sorted_tab(head->a, config, 0, 0);
		s = ft_path_finder(tab, 3 + i, head, config);
		ft_short_sort2(head, config, s);
		ft_pusha(head, config);
		i++;
		free(tab);
	}
	min_val(head, config, config->count);
}
