/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:50:50 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:50:52 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	nbr_whitespace(t_specs *specs, char *str, int len, int *ret)
{
	if (str[0] == '-' && specs->precision >= len)
		specs->width--;
	while (specs->width > len && specs->width > specs->precision
		&& specs->precision != 0)
	{
		ft_putchar_ret(' ', ret);
		specs->width--;
	}
	if (specs->precision == 0 && str[0] == '0' && specs->width > 0)
		specs->width++;
	while (specs->width > len && specs->precision <= 0)
	{
		ft_putchar_ret(' ', ret);
		specs->width--;
	}
}

void	nbr_padding(t_specs *specs, char *str, int len, int *ret)
{
	ft_putstr(str, ret);
	if (specs->precision == -1)
		ft_putstr(str, ret);
	while ((specs->width - specs->precision > len) || (specs->width > len))
	{
		ft_putchar_ret(' ', ret);
		specs->width--;
	}
}

/*
** If the number is negative print a '-' sign, add 1 to specs->precision.
** Print '0' while len is less than specs->precision OR
** len is less than width and flag is '0'. It avoids cutting the number if
** the specs->precision is less than the len of the number.
** Finally, print the digits if the first digit is not '0' and specs->precision
** is not 0.
*/

void	nbr_zero_padding(t_specs *specs, char *str, int len, int *ret)
{
	int	n;

	n = specs->precision;
	if (str[0] == '-')
	{
		ft_putchar_ret('-', ret);
		str++;
		n++;
	}
	while ((specs->flag == '0' && specs->width > len) || n > len)
	{
		ft_putchar_ret('0', ret);
		len++;
	}
	if (!(n == 0 && str[0] == '0'))
		ft_putstr(str, ret);
}
