# include "../pipex.h"

int	forking(int n)
{
	int	id;

	if (pipe(cmds()[0][n].fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}
	/* fprintf(stderr ,"cmd fd -> %d\n", cmds()[0][n].fd[0]); */
	id = fork();
	return(id);
}

int child_or_parente(char **envp, int n, int id)
{
	if (id == 0)
	{
		if(n == 0)
		{
			fprintf(stderr ,"entrou\n");
			file()[0][0].fd = open(file()[0][0].file, O_RDONLY);
			child(file()[0][0].fd, cmds()[0][n].fd[1], envp, n);
			return (0);
		}
		else if(n == utils()->ac - 4)
		{
			file()[0][1].fd = open(file()[0][1].file, O_RDWR | O_CREAT | O_TRUNC, 0777);
			fprintf(stderr ,"entrou_2\n");
			child(cmds()[0][n - 1].fd[0], file()[0][1].fd, envp, n);
			return (0);
		}
		else
		{
			fprintf(stderr ,"entrou_3\n");
			child(cmds()[0][n - 1].fd[0], cmds()[0][n].fd[1], envp, n);
			return (0);
		}
		return (0);
	}
	return (0);
}
