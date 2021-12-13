/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:49:50 by alpascal          #+#    #+#             */
/*   Updated: 2021/10/27 11:49:17 by alpascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int	init_gnl(char **s, int fd, char **line)
{
	if (*s == 0)
		*s = ft_strdup("");
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !s)
		return (-1);
	return (0);
}
