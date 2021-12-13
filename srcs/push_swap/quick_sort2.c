/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:20:13 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/10 18:06:47 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*tab_sort(int i, int f, int *tab)
{
	int	tmp;

	while (i < f - 1)
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
	return (tab);
}

int	*sorted_tab(t_stack *a, t_config *config, int f, int t)
{
	int	*tab;
	int	i;

	if (!f)
		f = config->count;
	tab = malloc(sizeof(int *) * config->count);
	if (!tab)
		return (NULL);
	i = 0;
	while (a->next && i < config->count)
	{
		tab[i] = a->val;
		a = a->next;
		i++;
	}
	tab[i] = a->val;
	if (!t)
		return (tab);
	i = 0;
	tab = tab_sort(i, f, tab);
	return (tab);
}

int	chunk_stack3(t_head *head, t_config *config, int *tab, int nb)
{
	int	i;
	int	l;
	int	m;

	i = config->count / 2;
	l = i - (config->s * nb);
	m = i + (config->s * nb);
	if (l < 0)
		l = 0;
	if (m > (config->count - 1))
		m = config->count - 1;
	if (head->a->val < tab[i - (nb - 1) * config->s] && head->a->val >= tab[l])
		ft_pushb(head, config);
	else if (head->a->val >= tab[i + (nb - 1) * config->s]
		&& head->a->val < tab[m])
	{
		ft_pushb(head, config);
		ft_rotateb(head, config);
	}
	else
	{
		ft_rotatea(head, config);
		return (0);
	}
	return (1);
}

void	chunk_stack2(t_head *head, t_config *config, int *tab, int nb)
{
	int	k;
	int	test;

	test = 0;
	k = 0;
	while (k <= (config->count - 1) && head->a->next && test < config->s * 2)
	{
		test += chunk_stack3(head, config, tab, nb);
		k++;
	}
}

void	chunk_stack(t_head *head, t_config *config, int *tab)
{
	int	p;
	int	i;

	p = config->count;
	i = 1;
	while (p > 0)
	{
		chunk_stack2(head, config, tab, i);
		i++;
		p = p - (config->s * 2);
	}
	ft_pushb(head, config);
	ft_rotateb(head, config);
}
