/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:43:07 by alpascal          #+#    #+#             */
/*   Updated: 2021/11/08 14:50:29 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_int(char *str)
{
	int		i;
	double	nb;
	int		sign;
	int		minus;

	i = 0;
	nb = 0;
	sign = 0;
	minus = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		sign++;
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	if ((minus == 1 && nb > 2147483648) || (minus == 0 && nb > 2147483647))
		return (0);
	return (1);
}
