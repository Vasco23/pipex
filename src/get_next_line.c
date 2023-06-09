/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:22:18 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/20 16:17:49 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	cursor[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (cursor[fd][0] || read(fd, cursor[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, cursor[fd]);
		if (ft_strlen(cursor[fd]) == 0)
			return (line);
		if (ft_clean(cursor[fd]) == 1)
			break ;
		if (read(fd, cursor[fd], 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
