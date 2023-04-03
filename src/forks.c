# include "../pipex.h"

/* int	forking(t_cmds *cmds, int n)
{
	int	id;

	if (pipe(cmds[n].fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}
	fprintf(stderr ,"cmd fd -> %d\n", cmds[n].fd[0]);
	id = fork();
	return(id);
} */

int child_or_parente(char **envp, int n)
{
	int id;
	int fd[2];
	if (pipe(fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}
	id = fork();
	if (id < 0)
	{
		perror("fork failed");
		return (-1);
	}
	if (id == 0)
	{
		if(n == 0)
		{
			fprintf(stderr ,"entrou\n");
			file()[0][0].fd = open(file()[0][0].file, O_RDONLY);
			child(file()[0][0].fd, fd[1], envp, n);
		}
		if(n == utils()->ac - 4)
		{
			file()[0][1].fd = open(file()[0][1].file, O_RDWR | O_CREAT | O_TRUNC, 0777);
			fprintf(stderr ,"entrou_2\n");
			child(fd[0], file()[0][1].fd, envp, n);
		}
		else
		{
			fprintf(stderr ,"entrou_3\n");
			child(fd[0], fd[1], envp, n);
		}
	}
	
	return (0);
}
