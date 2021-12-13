/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:32 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:48:34 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s)
	{
		if (ft_strlen((char *)s) <= start)
			return (ft_strdup(""));
		s_len = ft_strlen((char *)s);
		dst = (char *)ft_calloc(len + 1, sizeof(*dst));
		if (dst == NULL)
			return (NULL);
		if (start < s_len)
		{
			while (i < len && s[start])
				dst[i++] = s[start++];
			return (dst);
		}
	}
	return (NULL);
}
