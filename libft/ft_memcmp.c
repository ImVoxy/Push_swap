/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:31 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:45:33 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*ptr_s1++ != *ptr_s2++)
			return (*--ptr_s1 - *--ptr_s2);
		n--;
	}
	return (0);
}
