/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:13:58 by vcacador          #+#    #+#             */
/*   Updated: 2023/06/28 15:58:34 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int		here_doc_do(int fd);
size_t	ft_strlen_2(const char *str );

void	forking(void)
{
	int	i;

	i = 0;
	while (i < utils()->ac - 2)
	{
		if (pipe(cmds()[0][i].fd) == -1)
		{
			perror("error on pipe");
			return ;
		}
		i++;
	}
}

int	child_or_parente(char **envp, int n, int j)
{
	if (j == 1 && n == 1)
	{
		here_doc_do(cmds()[0][n - 1].fd[1]);
		close(cmds()[0][n - 1].fd[1]);
		child(cmds()[0][n - 1].fd[0], cmds()[0][n].fd[1], envp, n);
	}
	else if (n == 0)
	{
		(file()[0][0].fd) = open(file()[0][0].file, O_RDONLY);
		if (file()[0][0].fd < 0)
			return (1);
		child(file()[0][0].fd, cmds()[0][n].fd[1], envp, n);
	}
	else if (n == utils()->ac - 4)
	{
		(file()[0][1].fd)
			= open(file()[0][1].file, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (file()[0][1].fd < 0)
			return (1);
		child(cmds()[0][n - 1].fd[0], file()[0][1].fd, envp, n);
	}
	else if (n != 1 || j != 1)
		child(cmds()[0][n - 1].fd[0], cmds()[0][n].fd[1], envp, n);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((s1)[i] - (s2)[i]);
		i++;
	}
	return (0);
}

int	here_doc_do(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		printf("line - [%s]\n", line);
		printf("comd - [%s]\n", cmds()[0][0].cmd[0]);
		if (!ft_strcmp(cmds()[0][0].cmd[0], line) &&
			(ft_strlen_2(line) == ft_strlen_2(cmds()[0][0].cmd[0])))
		{
			free(line);
			return (1);
		}
		write(fd, line, strlen(line));
		free(line);
	}
	return (0);
}

size_t	ft_strlen_2(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
