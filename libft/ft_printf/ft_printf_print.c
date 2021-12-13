/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:50:43 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:50:46 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(va_list params, t_specs *specs, int *ret)
{
	unsigned char	c;
	char			padding;

	c = va_arg(params, int);
	if (specs->flag == '0')
		padding = '0';
	else
		padding = ' ';
	if (specs->flag == '-')
		ft_putchar_ret(c, ret);
	while (specs->width-- > 1)
		ft_putchar_ret(padding, ret);
	if (specs->flag != '-')
		ft_putchar_ret(c, ret);
}

/*
** print len chars in the string, while len is less than the precision.
** if no precision, print the whole string.
** Before printing, check the flags.
*/

void	print_str(va_list params, t_specs *specs, int *ret)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(params, char *);
	if (!str)
		str = "(null)";
	while ((len < specs->precision || specs->precision == -1) && str[len])
		len++;
	if (specs->flag == '-')
		str_padding(specs, str, len, ret);
	else if (specs->flag == '0')
		str_zero_padding(specs, str, len, ret);
	else
		str_whitespace(specs, str, len, ret);
}

/*
** if the pointer is NULL, itoa_base will return zero. Replace it by
** an empty string to avoid printing when there is a precision char.
** Result should be --> "0x".
*/

void	print_pointer(va_list params, t_specs *specs, int *ret)
{
	long int	nb;
	int			len;
	char		*str;

	len = 0;
	nb = (long int)va_arg(params, void *);
	str = itoa_base(nb, 16, "0123456789abcdef");
	if (str[0] == '0' && specs->precision != -1)
		str[0] = '\0';
	if (specs->flag == '-')
		specs->width -= 2;
	while (str[len])
		len++;
	check_p_flag(specs, str, len, ret);
}

void	print_integer(va_list params, t_specs *specs, int *ret)
{
	int				nb;
	unsigned int	nbu;
	char			*str;

	if (specs->type == 'u')
	{
		nbu = va_arg(params, unsigned int);
		str = itoa_base(nbu, 10, "0123456789");
		check_nbr_flag(specs, str, ret);
	}
	else
	{
		nb = va_arg(params, int);
		str = itoa_base(nb, 10, "0123456789");
		check_nbr_flag(specs, str, ret);
	}
}

void	print_dectohexa(va_list params, t_specs *specs, int *ret)
{
	char			*tab;
	char			*str;
	unsigned int	nb;

	if (specs->type == 'X')
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	nb = va_arg(params, unsigned int);
	str = itoa_base(nb, 16, tab);
	check_nbr_flag(specs, str, ret);
}
