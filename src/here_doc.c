/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:01:15 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/20 15:57:56 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	here_doc(char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[2]) > 0)
	{
		utils()->here_doc = 1;
		if (utils()->ac < 6)
		{
			perror("error not 2 cmds");
			exit(1);
		}
		return (0);
	}
	return (1);
}
