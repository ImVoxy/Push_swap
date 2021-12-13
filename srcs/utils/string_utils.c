/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:05:47 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/13 01:41:52 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_args(char **args, int i)
{
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			while (args[i][j] == ' ' || args[i][j] == '\t')
				j++;
			if (args[i][j] && !(ft_isdigit(args[i][j])) && !(args[i][j] == '-'
				&& ft_isdigit(args[i][j + 1])))
				return (0);
			else if (args[i][j] == '-')
				j++;
			if (args[i][j])
				count++;
			while (ft_isdigit(args[i][j]))
				j++;
		}
		i++;
	}
	return (count);
}

int	*init_tab(char **args)
{
	int	i;
	int	*tab;

	tab = ft_calloc(count_args(args, 0) + 1, sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	return (tab);
}

int	check_doubles(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args2(char *args, int **tab, int *i)
{
	int	j;

	j = 0;
	while (args[j])
	{
		while (args[j] && (args[j] == ' ' || args[j] == '\t'))
			j++;
		if (args[j] && !(ft_isdigit(args[j])) && !(args[j] == '-'
				&& (ft_isdigit(args[j + 1]))))
			return (0);
		if (!check_int(&(args[j])))
			return (0);
		tab[0][*i] = ft_atoi(&(args[j]));
		*i += 1;
		if (args[j] == '-')
			j++;
		while (ft_isdigit(args[j]))
			j++;
		if (args[j] && args[j] != ' ' && args[j] != '\t')
			return (0);
	}
	return (1);
}

int	*check_args(char **args)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = init_tab(args);
	while (args[i])
	{
		if (!check_args2(args[i], &tab, &j))
			return (exit_checker(tab, 0));
		i++;
	}
	if (check_doubles(tab, count_args(args, 0)))
		return (exit_checker(tab, 0));
	return (exit_checker(tab, 1));
}
