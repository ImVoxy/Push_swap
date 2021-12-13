/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:16:11 by alpascal          #+#    #+#             */
/*   Updated: 2021/12/10 18:08:51 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_head
{
	struct s_stack	*a;
	struct s_stack	*b;
}				t_head;

typedef struct s_config
{
	int	count;
	int	min;
	int	max;
	int	s;
	int	op;
}				t_config;

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

/*
**		operations
*/

void	ft_swapa(t_head *head, t_config *config);
void	ft_swapb(t_head *head, t_config *config);
void	ft_swaps(t_head *head, t_config *config);
void	ft_pusha(t_head *head, t_config *config);
void	ft_pushb(t_head *head, t_config *config);
void	ft_rotatea(t_head *head, t_config *config);
void	ft_rotateb(t_head *head, t_config *config);
void	ft_rotater(t_head *head, t_config *config);
void	ft_rev_rotatea(t_head *head, t_config *config);
void	ft_rev_rotateb(t_head *head, t_config *config);
void	ft_rev_rotater(t_head *head, t_config *config);

/*
**		push_swap
*/

int		*sorted_tab(t_stack *a, t_config *config, int f, int t);
void	parse_stack(t_stack *a, t_config *config);
void	ft_threesort(t_head *head, t_config *config);
void	ft_insert_sort(t_head *head, t_config *config);
void	ft_quick_sort(t_head *head, t_config *config);
void	chunk_stack(t_head *head, t_config *config, int *tab);
void	subdiv_sort2(t_head *head, t_config *config, int k);
void	ft_short_sort(t_head *head, t_config *config, int j, int i);
void	ft_short_sort2(t_head *head, t_config *config, int s);
int		mid_value(t_stack *a, int j);

/*
**		utils
*/

int		main(int argc, char **argv);
void	init_stack(int len, int *val, t_head **head);
int		*check_args(char **args);
void	ft_cleanup(t_head *head, t_config *config, int *tab);
void	quick_sort(t_head *head, t_config *config);
int		*exit_checker(int *tab, int i);
int		count_args(char **args, int i);
int		check_int(char *str);

#endif