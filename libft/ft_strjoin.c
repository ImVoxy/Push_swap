/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:47:13 by alpascal          #+#    #+#             */
/*   Updated: 2021/04/08 15:47:15 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		len;

	if (s1 && s2)
	{
		tab = NULL;
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		tab = malloc(sizeof(char) * len);
		if (!tab)
			return (0);
		tab[0] = '\0';
		tab = ft_strcat(tab, s1);
		tab = ft_strcat(tab, s2);
		return (tab);
	}
	return (NULL);
}
