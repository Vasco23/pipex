# include "../pipex.h"

int	forking(t_cmds *cmds, int n)
{
	int	id;

	if (pipe(cmds[n].fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}
	id = fork();
	printf("id -> %d, n -> %d\n", id, n);
	return(id);
}

int child_or_parente(int id, char **envp, int n)
{
	fprintf(stderr ,"times -> %d\n", n);
	if (id < 0)
	{
		perror("fork failed");
		return (-1);
	}
	if (id == 0)
	{
		if(n == 0)
		{
			*file()[0].fd = open(*file()[0].file)
			child(*file()[0].fd, *cmds()[n], envp);
		}
		if(n == ac - 2)
		{
			*file()[1].fd = open(*file()[1].file)
			child(*file()[1].fd, *cmds()[n].fd[0], envp);
		}
		else
		{
			
		}
		return (0);
	}
	if (id > 0)
	{
		printf("entrou29\n");
		wait(NULL);
	}
	return (0);
}
