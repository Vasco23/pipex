# include "../pipex.h"

int forking(t_cmds *cmds, int n)
{
	if (pipe(cmds[n].fd) == -1)
	{
		perror("error on pipe");
		return (-1);
	}
	int id;

	id = fork();
	return(id);
}

int child_or_parente(int id, int n, char **envp)
{
	if (id < 0)
	{
		perror("fork failed");
		return (-1);
	}
	if (id > 0)
	{
		wait(NULL);
	}
	if(id == 0)
		child(*cmds(), *file(), n, envp);
	return (0);
}