/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:10 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:45:11 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*ptr_str;
	unsigned int	i;

	ptr_str = str;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == c)
		{
			ptr_str += i;
			return ((char *)ptr_str);
		}
		i++;
	}
	return (NULL);
}
