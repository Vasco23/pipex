/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:06:35 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/20 15:40:40 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	child(int fd_in, int fd_out, char **envp, int n)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			perror("error");
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			perror("error");
		close(fd_in);
		close(fd_out);
		(utils()->path) = do_comand(*cmds(), get_path(envp), n);
		if (execve(utils()->path, cmds()[0][n].cmd, envp) == -1)
		{
			perror("error");
			free(utils()->path);
			return (1);
		}
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
