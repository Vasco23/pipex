# include "../inc/pipex.h"

int here_doc_do(int fd);
size_t	ft_strlen_2(const char *str );

void	forking(void)
{
	int i;
	
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
		file()[0][0].fd = open(file()[0][0].file, O_RDONLY);
		if (file()[0][0].fd < 0)
			return (1);
		child(file()[0][0].fd, cmds()[0][n].fd[1], envp, n);
	}
	else if (n == utils()->ac - 4)
	{
		file()[0][1].fd = open(file()[0][1].file, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (file()[0][1].fd < 0)
			return (1);
		child(cmds()[0][n - 1].fd[0], file()[0][1].fd, envp, n);
	}
	else if (n != 1 || j != 1)
		child(cmds()[0][n - 1].fd[0], cmds()[0][n].fd[1], envp, n);
	return (0);
}


int here_doc_do(int fd)
{
	int i;

	i = 0;
	char *line;
	while (1)
	{
		line = get_next_line(0);
		if (ft_strlen(line) == 0)
			i = 2;
		else
			i = ft_strlen_2(line);
		if (ft_strncmp(cmds()[0][0].cmd[0], line, i) == 0 
			&& i == (int)ft_strlen_2(cmds()[0][0].cmd[0]))
		{
			free(line);
			return(1);
		}
		write(fd, line, strlen(line));
		free(line);
	}
	return (0);
}

size_t	ft_strlen_2(const char *str )
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
