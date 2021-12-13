/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertbase.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:51:01 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:51:02 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	strlen_base(long int nb, int base)
{
	int	i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb != 0 && i++ < base)
		nb = nb / base;
	return (i);
}

static char	*print_zero_base(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*itoa_base(long int nb, int base, char *tab)
{
	char		*str;
	int			len;
	long int	tmp;

	len = strlen_base(nb, base);
	tmp = nb;
	if (nb == 0)
		return (print_zero_base());
	else
	{
		if (nb < 0)
			tmp *= -1;
		str = malloc(sizeof(char) * len);
		if (!str)
			return (NULL);
		str[len] = '\0';
		if (nb < 0)
			str[0] = '-';
		while (len > 0 && tmp != 0)
		{
			str[--len] = tab[tmp % base];
			tmp = tmp / base;
		}
	}
	return (str);
}

int	mini_atoi(const char *str, int *i)
{
	unsigned int	nb;

	nb = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (nb);
}
