/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:52:56 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/10 18:08:42 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	mid_value(t_stack *a, int j)
{
	int	tab[20];
	int	i;
	int	tmp;

	i = 0;
	while (a->next && i < j - 1)
	{
		tab[i] = a->val;
		a = a->next;
		i++;
	}
	tab[i] = a->val;
	i = 0;
	while (i < (j - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab[((j - 1) / 2)]);
}

int	*ft_inf_spot(t_head *head, t_config *config, int *tab, int i)
{
	int	tmp;
	int	tmp2;
	int	tmp3;

	tmp = i;
	tmp2 = tab[i];
	while (i > 0 && head->b->val < tab[i - 1])
	{
		ft_rev_rotatea(head, config);
		i--;
	}
	tmp3 = tab[i];
	tab[i] = tmp2;
	tmp2 = tmp3;
	ft_pusha(head, config);
	while (i <= tmp)
	{
		ft_rotatea(head, config);
		i++;
		tmp3 = tab[i];
		if (i <= tmp)
			tab[i] = tmp2;
		tmp2 = tmp3;
	}
	return (tab);
}

void	subdiv_sort2(t_head *head, t_config *config, int k)
{
	int	i;
	int	*tab;

	i = 0;
	tab = sorted_tab(head->a, config, k, 0);
	if (!tab)
		return ;
	while (i < k)
	{
		if (i > 0 && tab[i] < tab[i - 1])
		{
			ft_pushb(head, config);
			tab = ft_inf_spot(head, config, tab, i);
		}
		else
			ft_rotatea(head, config);
		i++;
	}
	i = 0;
	free(tab);
}

void	subdiv_sort(t_head *head, t_config *config, int i, int nb)
{
	int	k;
	int	p;
	int	l;

	k = 0;
	l = 0;
	p = mid_value(head->b, i);
	while (k <= nb)
	{
		if (head->b->val < p)
		{
			ft_pusha(head, config);
			ft_rotatea(head, config);
			l++;
		}
		else
			ft_pusha(head, config);
		k++;
	}
	p = 0;
	while (p++ < l)
		ft_rev_rotatea(head, config);
	subdiv_sort2(head, config, k);
}

void	quick_sort(t_head *head, t_config *config)
{
	int	i;
	int	*tab;
	int	j;

	i = 0;
	j = config->count % (config->s * 2);
	tab = sorted_tab(head->a, config, 0, 1);
	if (!tab)
		return ;
	chunk_stack(head, config, tab);
	if (j > 1)
		subdiv_sort(head, config, j / 2, (j / 2) - 1);
	while ((config->count - (i * config->s) - j) >= config->s)
	{
		subdiv_sort(head, config, config->s, (config->s - 1));
		i++;
	}
	if (j > 0)
		subdiv_sort(head, config, (j / 2 + j % 2), (j / 2 + j % 2) - 1);
	free(tab);
}
