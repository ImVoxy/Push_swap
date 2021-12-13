/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:31 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:46:33 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			ft_putstr_fd("2147483648", fd);
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
