# include "../pipex.h"

int forking(t_cmds *cmds, int n)
{
	int id;
	
	if (pipe(cmds[n].fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}

	id = fork();
	printf("%d\n", id);
	return(id);
}

int child_or_parente(int id, char **envp)
{
	static int times;

		/* fprintf(2 ,"entrou\n"); */
	if (id < 0)
	{
		perror("fork failed");
		return (-1);
	}
	if (id == 0)
	{
		child(*cmds(), *file(), times, envp);
		times++;
		return (0);
	}
	if (id > 0 && times > 11)
	{
		printf("entrou29\n");
		wait(NULL);
	}
	times++;
	return (0);
}
