/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:50:35 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:50:37 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_ret(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

void	ft_putstr(char *str, int *ret)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_ret(str[i++], ret);
}

/*
** if width > len, print (width - len) whitespace(s) then print the string
*/

void	str_whitespace(t_specs *specs, char *str, int len, int *ret)
{
	int	i;

	i = 0;
	while (specs->width - len > 0)
	{
		ft_putchar_ret(' ', ret);
		specs->width--;
	}
	while (i < len)
		ft_putchar_ret(str[i++], ret);
}

/*
** Align to the left. Print the string then
** print whitespaces up to the total width if necessary
*/

void	str_padding(t_specs *specs, char *str, int len, int *ret)
{
	int	i;

	i = 0;
	while (i < len)
		ft_putchar_ret(str[i++], ret);
	while (specs->width - len > 0)
	{
		ft_putchar_ret(' ', ret);
		specs->width--;
	}
}

/*
** if width > len, print (width - len) zero char(s) then print the string
*/

void	str_zero_padding(t_specs *specs, char *str, int len, int *ret)
{
	int	i;

	i = 0;
	while (specs->width - len > 0)
	{
		ft_putchar_ret('0', ret);
		specs->width--;
	}
	while (i < len)
		ft_putchar_ret(str[i++], ret);
}
