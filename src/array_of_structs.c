/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:04:51 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/28 16:05:13 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_array_of_structs(t_file *file, t_cmds *cmds, int ac, char **av)
{
	int	i;
	int	f;
	int	c;

	i = 1;
	c = 0;
	f = 0;
	while (i < ac)
	{
		if (i == 1 || i == ac - 1)
		{
			file[f].file = ft_strdup(av[i]);
			f++;
		}
		else if (utils()->here_doc == 1 && i == 2)
			cmds[c++].cmd = ft_split(av[i], '\0');
		else
			cmds[c++].cmd = ft_split(av[i], ' ');
		i++;
	}
}

t_cmds	**cmds(void)
{
	static t_cmds	*cmds;

	return (&cmds);
}

t_file	**file(void)
{
	static t_file	*file;

	return (&file);
}

void	malloc_struct(t_file **file, t_cmds **cmds, int ac)
{
	*cmds = malloc(sizeof(t_cmds) * (ac - 2));
	*file = malloc(sizeof(t_file) * 3);
	if (!cmds && !file)
	{
		free_all();
		exit(1);
	}
}
