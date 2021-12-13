/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:42:51 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:42:52 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_positive(char *tab, int nbr, int index)
{
	while (index >= 0)
	{
		tab[index] = nbr % 10 + 48;
		nbr = nbr / 10;
		index--;
	}
	return (tab);
}

static char	*ft_negative(char *tab, int nbr, int index)
{
	unsigned int	nbr_min;

	tab[0] = '-';
	while (index > 0)
	{
		if (nbr == INT_MIN)
		{
			nbr_min = nbr;
			tab[index] = nbr_min % 10 + 48;
			nbr = nbr / 10;
			index--;
		}
		else
		{
			tab[index] = -nbr % 10 + 48;
			nbr = nbr / 10;
			index--;
		}
	}
	return (tab);
}

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr >= 0)
	{
		if (nbr <= 9)
			return (len);
		while (nbr > 9)
		{
			nbr = nbr / 10;
			len++;
		}
	}
	else
	{
		len = 2;
		if (nbr >= -9)
			return (len);
		while (nbr < -9)
		{
			nbr = nbr / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = NULL;
	i = ft_nbrlen(n);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n >= 0)
		ft_positive(str, n, i);
	else
		ft_negative(str, n, i);
	return (str);
}
